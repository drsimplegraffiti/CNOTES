#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOTES 100
#define MAX_TITLE 50
#define MAX_CONTENT 500
#define DATE_LEN 30

struct Note {
  char title[MAX_TITLE];
  char content[MAX_CONTENT];
  char date[DATE_LEN];
};

struct Note notes[MAX_NOTES];
int totalNotes = 0;

void loadNotesFromFile();
void saveNotesToFile();
void addNote();
void viewNotes();
void searchNote();
void editNote();
void deleteNote();
void menu();
char *getCurrentDate();

int main() {
  loadNotesFromFile();

  int choice;
  bool running = true;

  while (running) {
    menu();
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar(); // clear buffer

    switch (choice) {
    case 1:
      addNote();
      break;
    case 2:
      viewNotes();
      break;
    case 3:
      searchNote();
      break;
    case 4:
      editNote();
      break;
    case 5:
      deleteNote();
      break;
    case 0:
      saveNotesToFile();
      printf("Exiting... Notes saved.\n");
      running = false;
      break;
    default:
      printf("Invalid choice!\n");
      break;
    }
  }

  return 0;
}

void menu() {
  printf("\n====== NOTE TAKING APP ======\n");
  printf("[1] Add Note\n");
  printf("[2] View All Notes\n");
  printf("[3] Search Note by Title\n");
  printf("[4] Edit Note\n");
  printf("[5] Delete Note\n");
  printf("[0] Exit\n");
  printf("=============================\n");
}

char *getCurrentDate() {
  static char buffer[DATE_LEN];
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", t);
  return buffer;
}

void addNote() {
  if (totalNotes >= MAX_NOTES) {
    printf("Note limit reached!\n");
    return;
  }

  struct Note newNote;
  printf("Enter title: ");
  fgets(newNote.title, MAX_TITLE, stdin);
  newNote.title[strcspn(newNote.title, "\n")] = 0;

  printf("Enter content: ");
  fgets(newNote.content, MAX_CONTENT, stdin);
  newNote.content[strcspn(newNote.content, "\n")] = 0;

  strcpy(newNote.date, getCurrentDate());

  notes[totalNotes++] = newNote;

  printf("Note added successfully!\n");
}

void viewNotes() {
  if (totalNotes == 0) {
    printf("No notes available.\n");
    return;
  }

  printf("\nAll Notes:\n");
  for (int i = 0; i < totalNotes; i++) {
    printf("\n[%d] Title: %s\n", i + 1, notes[i].title);
    printf("Date: %s\n", notes[i].date);
    printf("Content: %s\n", notes[i].content);
  }
}

void searchNote() {
  char query[MAX_TITLE];
  printf("Enter title to search: ");
  fgets(query, MAX_TITLE, stdin);
  query[strcspn(query, "\n")] = 0;

  for (int i = 0; i < totalNotes; i++) {
    if (strcmp(notes[i].title, query) == 0) {
      printf("\nNote Found:\n");
      printf("Title: %s\n", notes[i].title);
      printf("Date: %s\n", notes[i].date);
      printf("Content: %s\n", notes[i].content);
      return;
    }
  }
  printf("No note found with title '%s'\n", query);
}

void editNote() {
  char query[MAX_TITLE];
  printf("Enter title of note to edit: ");
  fgets(query, MAX_TITLE, stdin);
  query[strcspn(query, "\n")] = 0;

  for (int i = 0; i < totalNotes; i++) {
    if (strcmp(notes[i].title, query) == 0) {
      printf("Editing Note: %s\n", notes[i].title);

      printf("Enter new content: ");
      fgets(notes[i].content, MAX_CONTENT, stdin);
      notes[i].content[strcspn(notes[i].content, "\n")] = 0;

      strcpy(notes[i].date, getCurrentDate());

      printf("Note updated successfully!\n");
      return;
    }
  }
  printf("Note not found.\n");
}

void deleteNote() {
  char query[MAX_TITLE];
  printf("Enter title of note to delete: ");
  fgets(query, MAX_TITLE, stdin);
  query[strcspn(query, "\n")] = 0;

  for (int i = 0; i < totalNotes; i++) {
    if (strcmp(notes[i].title, query) == 0) {
      for (int j = i; j < totalNotes - 1; j++) {
        notes[j] = notes[j + 1];
      }
      totalNotes--;
      printf("Note deleted successfully!\n");
      return;
    }
  }
  printf("Note not found.\n");
}

void loadNotesFromFile() {
  FILE *f = fopen("notes.txt", "r");
  if (!f)
    return;

  while (fscanf(f, " %[^\n]\n %[^\n]\n %[^\n]\n", notes[totalNotes].title,
                notes[totalNotes].content, notes[totalNotes].date) == 3) {
    totalNotes++;
  }

  fclose(f);
}

void saveNotesToFile() {
  FILE *f = fopen("notes.txt", "w");
  if (!f) {
    printf("Error saving notes!\n");
    return;
  }

  for (int i = 0; i < totalNotes; i++) {
    fprintf(f, "%s\n%s\n%s\n", notes[i].title, notes[i].content, notes[i].date);
  }

  fclose(f);
}
