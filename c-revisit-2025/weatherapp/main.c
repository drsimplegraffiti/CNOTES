// main.c
#include <stdio.h>     // Standard input/output functions
#include <stdlib.h>    // Standard library functions like malloc(), free()
#include <string.h>    // String handling functions like memcpy()
#include <curl/curl.h> // libcurl for making HTTP requests
#include <cjson/cJSON.h> // cJSON for parsing JSON data

// ===========================
// 1. Structure to store the API response (dynamic memory)
// ===========================

struct MemoryStruct {
    char *memory;  // Pointer to hold the downloaded data
    size_t size;   // Size of the downloaded data
};

// ===========================
// 2. libcurl's callback function 
// Whenever libcurl receives a chunk of data, it calls this function
// ===========================

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb; // real size = size * number of memory blocks
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    // realloc resizes previously allocated memory to fit the new incoming data
    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (!ptr) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    // Copy the new contents into memory starting at the end of what we already have
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0; // Null-terminate the string

    return realsize;
}

// ===========================
// 3. Function to fetch weather data from OpenWeatherMap API
// ===========================

char *fetch_weather_data(const char *city_name) {
    CURL *curl_handle; // curl object to handle HTTP request
    CURLcode res;      // store curl's response status

    // Create a MemoryStruct to hold the response
    struct MemoryStruct chunk;
    chunk.memory = malloc(1); // Start with 1 byte
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL); // Initialize libcurl
    curl_handle = curl_easy_init();    // Create a handle to interact with

    if (curl_handle) {
        char url[256]; // Buffer to hold the full URL

        // Insert your API key here
        const char *api_key = "a05325d32c4eb160982666802fe099cb";

        // Build the URL with the city name and your API key
        snprintf(url, sizeof(url), 
            "https://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s&units=metric",
            city_name, api_key);

        // Set curl options
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback); 
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

        // Perform the HTTP GET request
        res = curl_easy_perform(curl_handle);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            free(chunk.memory);
            chunk.memory = NULL;
        }

        // Clean up curl
        curl_easy_cleanup(curl_handle);
    }

    // Finalize libcurl
    curl_global_cleanup();

    return chunk.memory; // Return the downloaded JSON response
}

// ===========================
// 4. Function to parse the JSON response and display weather details
// ===========================

void display_weather(const char *json_data) {
    printf("Raw API response:\n%s\n", json_data);

    // Parse the JSON string
    cJSON *root = cJSON_Parse(json_data);
    if (!root) {
        printf("Error parsing JSON.\n");
        return;
    }

    // Extract specific parts of the JSON
    cJSON *name = cJSON_GetObjectItemCaseSensitive(root, "name"); // City name
    cJSON *main = cJSON_GetObjectItemCaseSensitive(root, "main"); // Main weather data (temp, humidity)
    cJSON *weather_array = cJSON_GetObjectItemCaseSensitive(root, "weather"); // Array of weather conditions
    cJSON *wind = cJSON_GetObjectItemCaseSensitive(root, "wind"); // Wind data

    if (name && main && weather_array && cJSON_IsArray(weather_array)) {
        double temp = cJSON_GetObjectItem(main, "temp")->valuedouble; // temperature
        double humidity = cJSON_GetObjectItem(main, "humidity")->valuedouble; // humidity %
        double wind_speed = cJSON_GetObjectItem(wind, "speed")->valuedouble; // wind speed

        // Weather description (e.g., "clear sky", "light rain")
        cJSON *weather = cJSON_GetArrayItem(weather_array, 0);
        char *description = cJSON_GetObjectItem(weather, "description")->valuestring;

        // Print the extracted data
        printf("City: %s\n", name->valuestring);
        printf("Temperature: %.2f°C\n", temp);
        printf("Humidity: %.2f%%\n", humidity);
        printf("Wind Speed: %.2fm/s\n", wind_speed);
        printf("Weather: %s\n", description);
    } else {
        printf("Incomplete data received.\n");
    }

    // Free the memory allocated for the JSON structure
    cJSON_Delete(root);
}

// ===========================
// 5. Main program entry point
// ===========================

int main() {
    char city[100];
    
    printf("Enter city name: ");
    scanf("%s", city); // Get user input

    // Fetch the weather data for the entered city
    char *weather_data = fetch_weather_data(city);
    
    if (weather_data) {
        display_weather(weather_data); // Display parsed weather info
        free(weather_data);            // Free the allocated memory
    } else {
        printf("Failed to fetch weather data.\n");
    }

    return 0;
}

