// student_mgmt.c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

// configuration / limits
#define MAX_STUDENTS 100
#define MAX_COURSES 500
#define ID_LEN 10
#define NAME_LEN 20
#define EMAIL_LEN 30
#define PHONE_LEN 20
#define CODE_LEN 10
#define COURSE_NAME_LEN 20

typedef struct {
  char ID[ID_LEN + 1];
  char Name[NAME_LEN + 1];
  char Email[EMAIL_LEN + 1];
  char Phone[PHONE_LEN + 1];
  int NumberOfCourse;
} StudentInfo;

typedef struct {
  char StudentID[ID_LEN + 1];
  char Code[CODE_LEN + 1];
  char Name[COURSE_NAME_LEN + 1];
} CourseInfo;

// storage
static StudentInfo Students[MAX_STUDENTS];
static CourseInfo Courses[MAX_COURSES];

static int TotalStudents = 0;
static int TotalCourse = 0;
static bool IsRunning = true;

// prototypes
void ClearScreen(void);
void Menu(void);
void AddNewStudent(void);
void ShowAllStudents(void);
int SearchStudent(const char *studentID);
void EditStudent(int studentIndex);
void DeleteStudent(int studentIndex);
void DeleteAllStudents(void);
int IsAlreadyExists(const char *given, char infoType,
                    const char *currentStudentID);
void ErrorAndRestart(const char *error);
void DeleteCourseByIndex(int courseIndex);
void DeleteStudentByIndex(int studentIndex);
void UserGuideline(void);
void AboutUs(void);
void GoBackOrExit(void);
void ExitProject(void);
void DataSeed(void);

int main(void) {
  DataSeed(); // comment out if you don't want dummy data

  while (IsRunning) {
    Menu();
    int Option = -1;
    if (scanf("%d", &Option) != 1) {
      // invalid input - clear stdin
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      Option = -1;
    }

    switch (Option) {
    case 0:
      IsRunning = false;
      ExitProject();
      break;
    case 1:
      ClearScreen();
      printf("\n\t\t **** Add A New Student ****\n\n");
      AddNewStudent();
      GoBackOrExit();
      break;
    case 2:
      ClearScreen();
      printf("\n\t\t **** All Students ****\n\n");
      ShowAllStudents();
      GoBackOrExit();
      break;
    case 3: {
      char StudentID[ID_LEN + 1];
      ClearScreen();
      printf("\n\t\t **** Search Students ****\n\n");
      printf(" Enter The Student ID: ");
      if (scanf(" %10s", StudentID) == 1) {
        int idx = SearchStudent(StudentID);
        if (idx < 0) {
          printf(" No Student Found\n\n");
        }
      } else {
        printf(" Invalid input.\n\n");
      }
      GoBackOrExit();
      break;
    }
    case 4: {
      char StudentID[ID_LEN + 1];
      ClearScreen();
      printf("\n\t\t **** Edit a Student ****\n\n");
      printf(" Enter The Student ID: ");
      if (scanf(" %10s", StudentID) == 1) {
        int idx = SearchStudent(StudentID);
        if (idx >= 0) {
          EditStudent(idx);
        } else {
          printf(" No Student Found\n\n");
        }
      } else {
        printf(" Invalid input.\n\n");
      }
      GoBackOrExit();
      break;
    }
    case 5: {
      char StudentID[ID_LEN + 1];
      ClearScreen();
      printf("\n\t\t **** Delete a Student ****\n\n");
      printf(" Enter The Student ID: ");
      if (scanf(" %10s", StudentID) == 1) {
        int idx = SearchStudent(StudentID);
        if (idx >= 0) {
          char Sure = 'N';
          int ch = getchar(); // consume newline
          printf("\n\n Are you sure want to delete this student? (Y/N): ");
          if (scanf(" %c", &Sure) == 1 && (Sure == 'Y' || Sure == 'y')) {
            DeleteStudent(idx);
          } else {
            printf(" Your Data is Safe.\n\n");
            GoBackOrExit();
          }
        } else {
          printf(" No Student Found\n\n");
          GoBackOrExit();
        }
      } else {
        printf(" Invalid input.\n\n");
        GoBackOrExit();
      }
      break;
    }
    case 6: {
      char Sure = 'N';
      ClearScreen();
      printf("\n\t\t **** Delete ALL Students ****\n\n");
      printf(" Are you sure want to delete all the students? (Y/N): ");
      if (scanf(" %c", &Sure) == 1 && (Sure == 'Y' || Sure == 'y')) {
        DeleteAllStudents();
      } else {
        printf(" Your Data is Safe.\n\n");
        GoBackOrExit();
      }
      break;
    }
    case 7:
      ClearScreen();
      break;
    case 8:
      ClearScreen();
      UserGuideline();
      GoBackOrExit();
      break;
    case 9:
      ClearScreen();
      AboutUs();
      GoBackOrExit();
      break;
    default:
      ClearScreen();
      printf(" Invalid choice. Please try again.\n");
      break;
    }
  }

  return 0;
}

void ClearScreen(void) { system(CLEAR_COMMAND); }

void Menu(void) {
  printf("\n\n\t***Student Management System Using C***\n\n");
  printf("\t\t\tMAIN MENU\n");
  printf("\t\t=======================\n");
  printf("\t\t[1] Add A New student.\n");
  printf("\t\t[2] Show All students.\n");
  printf("\t\t[3] Search A student.\n");
  printf("\t\t[4] Edit A student.\n");
  printf("\t\t[5] Delete A student.\n");
  printf("\t\t[6] Delete All students.\n");
  printf("\t\t[7] Clear The window.\n");
  printf("\t\t[8] User Guideline.\n");
  printf("\t\t[9] About Us.\n");
  printf("\t\t[0] Exit the Program.\n");
  printf("\t\t=======================\n");
  printf("\t\tEnter The Choice: ");
}

void AddNewStudent(void) {
  char StudentIDLocal[ID_LEN + 1] = {0};
  char NameLocal[NAME_LEN + 1] = {0};
  char PhoneLocal[PHONE_LEN + 1] = {0};
  char EmailLocal[EMAIL_LEN + 1] = {0};
  int NumberOfCourses = 0;
  char CourseCode[CODE_LEN + 1] = {0};
  char CourseName[COURSE_NAME_LEN + 1] = {0};

  // ID
  while (1) {
    printf(" Enter The ID: ");
    if (scanf(" %10s", StudentIDLocal) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input. Try again.\n");
      continue;
    }
    if (IsAlreadyExists(StudentIDLocal, 'i', "") > 0) {
      printf(" Error: This ID already exists.\n\n");
    } else if (strlen(StudentIDLocal) > ID_LEN) {
      printf(" Error: ID can not be more than %d characters.\n\n", ID_LEN);
    } else if (strlen(StudentIDLocal) == 0) {
      printf(" Error: ID can not be empty.\n\n");
    } else {
      break;
    }
  }

  // Name (allow spaces)
  while (1) {
    printf(" Enter The Name: ");
    if (scanf(" %19[^\n]", NameLocal) != 1) { // max NAME_LEN chars
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input. Try again.\n");
      continue;
    }
    if (strlen(NameLocal) > NAME_LEN) {
      printf(" Error: Name can not be more than %d characters.\n\n", NAME_LEN);
    } else if (strlen(NameLocal) == 0) {
      printf(" Error: Name can not be empty.\n\n");
    } else {
      break;
    }
  }

  // Email
  while (1) {
    printf(" Enter The Email: ");
    if (scanf(" %30s", EmailLocal) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input. Try again.\n");
      continue;
    }
    if (IsAlreadyExists(EmailLocal, 'e', "") > 0) {
      printf(" This Email already exists.\n");
    } else if (strlen(EmailLocal) > EMAIL_LEN) {
      printf(" Error: Email can not be more than %d characters.\n\n",
             EMAIL_LEN);
    } else if (strlen(EmailLocal) == 0) {
      printf(" Error: Email can not be empty.\n\n");
    } else {
      break;
    }
  }

  // Phone
  while (1) {
    printf(" Enter The Phone: ");
    if (scanf(" %20s", PhoneLocal) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input. Try again.\n");
      continue;
    }
    if (IsAlreadyExists(PhoneLocal, 'p', "") > 0) {
      printf(" This Phone Number already exists\n");
    } else if (strlen(PhoneLocal) > PHONE_LEN) {
      printf(" Error: Phone can not be more than %d characters.\n\n",
             PHONE_LEN);
    } else if (strlen(PhoneLocal) == 0) {
      printf(" Error: Phone can not be empty.\n\n");
    } else {
      break;
    }
  }

  // Number of courses
  while (1) {
    printf(" Number of courses: ");
    if (scanf("%d", &NumberOfCourses) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input. Try again.\n");
      continue;
    }
    if (NumberOfCourses <= 0 || NumberOfCourses > 4) {
      printf(" Error: Number of courses must be between 1 and 4.\n\n");
    } else {
      break;
    }
  }

  if (TotalStudents >= MAX_STUDENTS) {
    ErrorAndRestart("Max students reached.");
    return;
  }

  // store student
  strncpy(Students[TotalStudents].ID, StudentIDLocal, ID_LEN);
  Students[TotalStudents].ID[ID_LEN] = '\0';
  strncpy(Students[TotalStudents].Name, NameLocal, NAME_LEN);
  Students[TotalStudents].Name[NAME_LEN] = '\0';
  strncpy(Students[TotalStudents].Phone, PhoneLocal, PHONE_LEN);
  Students[TotalStudents].Phone[PHONE_LEN] = '\0';
  strncpy(Students[TotalStudents].Email, EmailLocal, EMAIL_LEN);
  Students[TotalStudents].Email[EMAIL_LEN] = '\0';
  Students[TotalStudents].NumberOfCourse = NumberOfCourses;
  TotalStudents++;

  // courses
  for (int idx = 0; idx < NumberOfCourses; idx++) {
    if (TotalCourse >= MAX_COURSES) {
      printf(" Warning: max courses reached, stopping course input.\n");
      break;
    }
    printf(" Enter Course %d Code: ", idx + 1);
    if (scanf(" %10s", CourseCode) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input, skipping this course.\n");
      continue;
    }
    printf(" Enter Course %d Name: ", idx + 1);
    if (scanf(" %19[^\n]", CourseName) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      CourseName[0] = '\0';
    }

    strncpy(Courses[TotalCourse].StudentID, StudentIDLocal, ID_LEN);
    Courses[TotalCourse].StudentID[ID_LEN] = '\0';
    strncpy(Courses[TotalCourse].Code, CourseCode, CODE_LEN);
    Courses[TotalCourse].Code[CODE_LEN] = '\0';
    strncpy(Courses[TotalCourse].Name, CourseName, COURSE_NAME_LEN);
    Courses[TotalCourse].Name[COURSE_NAME_LEN] = '\0';
    TotalCourse++;
  }

  printf("\n Student Added Successfully.\n\n");
}

void ShowAllStudents(void) {
  if (TotalStudents == 0) {
    printf(" No students to show.\n\n");
    return;
  }

  printf("|==========|====================|==============================|====="
         "===============|=============|\n");
  printf("|    ID    |        Name        |            Email             |     "
         "  Phone        |  NO.Course  |\n");
  printf("|==========|====================|==============================|====="
         "===============|=============|\n");

  for (int i = 0; i < TotalStudents; i++) {
    printf("|%-10s|%-20s|%-30s|%-20s|%-13d|\n", Students[i].ID,
           Students[i].Name, Students[i].Email, Students[i].Phone,
           Students[i].NumberOfCourse);
    printf("|----------|--------------------|------------------------------|---"
           "-----------------|-------------|\n");
  }
  printf("\n");
}

int SearchStudent(const char *studentID) {
  ClearScreen();
  int StudentFoundIndex = -1;

  for (int i = 0; i < TotalStudents; i++) {
    if (strcmp(studentID, Students[i].ID) == 0) {
      StudentFoundIndex = i;
      printf("\n One Student Found for ID: %s\n\n", studentID);
      printf(" Student Informations\n");
      printf("-------------------------\n");
      printf(" ID:    %s\n", Students[i].ID);
      printf(" Name:  %s\n", Students[i].Name);
      printf(" Email: %s\n", Students[i].Email);
      printf(" Phone: %s\n", Students[i].Phone);
      printf("\n Total Number of Courses: %d\n", Students[i].NumberOfCourse);
      break; // IDs are unique so break after found
    }
  }

  if (StudentFoundIndex < 0) {
    return -1;
  }

  int CourseCount = 0;
  for (int j = 0; j < TotalCourse; j++) {
    if (strcmp(studentID, Courses[j].StudentID) == 0) {
      CourseCount++;
      printf(" Course %d Code: %s\n", CourseCount, Courses[j].Code);
      printf(" Course %d Name: %s\n", CourseCount, Courses[j].Name);
    }
  }

  return StudentFoundIndex;
}

void EditStudent(int studentIndex) {
  printf("\n\t\t **** Update The Student ****\n\n");

  char NewName[NAME_LEN + 1] = {0};
  char NewPhone[PHONE_LEN + 1] = {0};
  char NewEmail[EMAIL_LEN + 1] = {0};
  int NewNumberOfCourses = -1;
  char studID[ID_LEN + 1];
  strncpy(studID, Students[studentIndex].ID, ID_LEN);
  studID[ID_LEN] = '\0';
  int OldTotalNumberOfCourse = Students[studentIndex].NumberOfCourse;

  // Name (0 to skip)
  while (1) {
    printf(" Enter The New Name(0 for skip): ");
    if (scanf(" %19[^\n]", NewName) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input. Try again.\n");
      continue;
    }
    if (strcmp(NewName, "0") == 0) {
      break;
    }
    if (strlen(NewName) > NAME_LEN) {
      printf(" Error: Name can not be more than %d characters.\n\n", NAME_LEN);
    } else if (strlen(NewName) == 0) {
      printf(" Error: Name can not be empty.\n\n");
    } else {
      break;
    }
  }

  // Email (0 to skip)
  while (1) {
    printf(" Enter The New Email(0 for skip): ");
    if (scanf(" %30s", NewEmail) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input. Try again.\n");
      continue;
    }
    if (strcmp(NewEmail, "0") == 0) {
      break;
    }
    if (strlen(NewEmail) > EMAIL_LEN) {
      printf(" Error: Email can not be more than %d characters.\n\n",
             EMAIL_LEN);
    } else if (strlen(NewEmail) == 0) {
      printf(" Error: Email can not be empty.\n\n");
    } else if (IsAlreadyExists(NewEmail, 'e', studID) > 0) {
      printf(" Error: This Email Already Exists.\n\n");
    } else {
      break;
    }
  }

  // Phone (0 to skip)
  while (1) {
    printf(" Enter The New Phone(0 for skip): ");
    if (scanf(" %20s", NewPhone) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input. Try again.\n");
      continue;
    }
    if (strcmp(NewPhone, "0") == 0) {
      break;
    }
    if (strlen(NewPhone) > PHONE_LEN) {
      printf(" Error: Phone can not be more than %d characters.\n\n",
             PHONE_LEN);
    } else if (strlen(NewPhone) == 0) {
      printf(" Error: Phone can not be empty.\n\n");
    } else if (IsAlreadyExists(NewPhone, 'p', studID) > 0) {
      printf(" Error: This Phone Number Already Exists.\n\n");
    } else {
      break;
    }
  }

  // Number of courses (0 to skip)
  while (1) {
    printf(" Number of New courses(0 for skip): ");
    if (scanf("%d", &NewNumberOfCourses) != 1) {
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      printf(" Invalid input. Try again.\n");
      continue;
    }
    if (NewNumberOfCourses == 0)
      break; // skip
    if (NewNumberOfCourses < 0 || NewNumberOfCourses > 4) {
      printf(" Error: A Student can have maximum 4 and Minimum 0 number of "
             "courses.\n\n");
    } else {
      break;
    }
  }

  if (strcmp(NewName, "0") != 0 && strlen(NewName) > 0) {
    strncpy(Students[studentIndex].Name, NewName, NAME_LEN);
    Students[studentIndex].Name[NAME_LEN] = '\0';
  }

  if (strcmp(NewEmail, "0") != 0 && strlen(NewEmail) > 0) {
    strncpy(Students[studentIndex].Email, NewEmail, EMAIL_LEN);
    Students[studentIndex].Email[EMAIL_LEN] = '\0';
  }

  if (strcmp(NewPhone, "0") != 0 && strlen(NewPhone) > 0) {
    strncpy(Students[studentIndex].Phone, NewPhone, PHONE_LEN);
    Students[studentIndex].Phone[PHONE_LEN] = '\0';
  }

  if (NewNumberOfCourses > 0) {
    int OldTotalCourse = Students[studentIndex].NumberOfCourse;
    Students[studentIndex].NumberOfCourse = NewNumberOfCourses;

    // find first course index for this student
    int FirstCourseIndex = -1;
    for (int dc = 0; dc < TotalCourse; dc++) {
      if (strcmp(studID, Courses[dc].StudentID) == 0) {
        FirstCourseIndex = dc;
        break;
      }
    }

    // delete old courses for student
    if (FirstCourseIndex >= 0) {
      for (int dc = 0; dc < OldTotalCourse; dc++) {
        DeleteCourseByIndex(
            FirstCourseIndex); // after each delete, array shifts left
      }
    }

    // add new courses
    char CourseCode[CODE_LEN + 1];
    char CourseName[COURSE_NAME_LEN + 1];
    for (int i = 1; i <= NewNumberOfCourses; i++) {
      if (TotalCourse >= MAX_COURSES) {
        printf(" Warning: cannot add more courses (max reached).\n");
        break;
      }
      printf(" Enter New Course %d Code: ", i);
      if (scanf(" %10s", CourseCode) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        CourseCode[0] = '\0';
      }
      printf(" Enter New Course %d Name: ", i);
      if (scanf(" %19[^\n]", CourseName) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        CourseName[0] = '\0';
      }

      strncpy(Courses[TotalCourse].StudentID, studID, ID_LEN);
      Courses[TotalCourse].StudentID[ID_LEN] = '\0';
      strncpy(Courses[TotalCourse].Code, CourseCode, CODE_LEN);
      Courses[TotalCourse].Code[CODE_LEN] = '\0';
      strncpy(Courses[TotalCourse].Name, CourseName, COURSE_NAME_LEN);
      Courses[TotalCourse].Name[COURSE_NAME_LEN] = '\0';
      TotalCourse++;
    }
  }

  printf(" Student Updated Successfully.\n\n");
}

void DeleteStudent(int studentIndex) {
  if (studentIndex < 0 || studentIndex >= TotalStudents) {
    printf(" Invalid student index.\n");
    return;
  }

  // delete courses belonging to this student
  StudentInfo thisStudent = Students[studentIndex];
  int firstCourseIndex = -1;
  for (int d = 0; d < TotalCourse; d++) {
    if (strcmp(thisStudent.ID, Courses[d].StudentID) == 0) {
      firstCourseIndex = d;
      break;
    }
  }
  if (firstCourseIndex >= 0) {
    for (int d = 0; d < thisStudent.NumberOfCourse; d++) {
      DeleteCourseByIndex(
          firstCourseIndex); // deleting at same index as array shifts left
    }
  }

  DeleteStudentByIndex(studentIndex);
  printf(" Student Deleted Successfully.\n\n");
  GoBackOrExit();
}

void DeleteAllStudents(void) {
  TotalStudents = 0;
  TotalCourse = 0;
  printf(" All Students Deleted Successfully.\n\n");
  GoBackOrExit();
}

void DeleteCourseByIndex(int courseIndex) {
  if (courseIndex < 0 || courseIndex >= TotalCourse)
    return;
  for (int c = courseIndex; c < TotalCourse - 1; c++) {
    Courses[c] = Courses[c + 1];
  }
  TotalCourse--;
}

void DeleteStudentByIndex(int studentIndex) {
  if (studentIndex < 0 || studentIndex >= TotalStudents)
    return;
  for (int s = studentIndex; s < TotalStudents - 1; s++) {
    Students[s] = Students[s + 1];
  }
  TotalStudents--;
}

int IsAlreadyExists(const char *given, char infoType,
                    const char *currentStudentID) {
  int EmailExists = 0;
  int PhoneExists = 0;
  int IDExists = 0;

  for (int ep = 0; ep < TotalStudents; ep++) {
    if (strcmp(given, Students[ep].ID) == 0) {
      IDExists++;
    }
    if (strcmp(given, Students[ep].Email) == 0 &&
        (currentStudentID == NULL ||
         strcmp(currentStudentID, Students[ep].ID) != 0)) {
      EmailExists++;
    }
    if (strcmp(given, Students[ep].Phone) == 0 &&
        (currentStudentID == NULL ||
         strcmp(currentStudentID, Students[ep].ID) != 0)) {
      PhoneExists++;
    }
  }

  if (infoType == 'i') {
    return IDExists;
  } else if (infoType == 'e') {
    return EmailExists;
  } else if (infoType == 'p') {
    return PhoneExists;
  } else {
    return 0;
  }
}

void ErrorAndRestart(const char *error) {
  printf("%s\n", error ? error : "Error");
  printf("Restarting the program...\n");
  exit(1);
}

void UserGuideline(void) {
  printf("\n\t\t **** How it Works? ****\n\n");
  printf(" -> You will only able to store the Student's ID, Name, Email, "
         "Phone, Number of Courses.\n");
  printf(" -> A student can have maximum 4 courses and minimum 1 course.\n");
  printf(" -> Student ID can be maximum %d characters long and unique for "
         "every student.\n",
         ID_LEN);
  printf(" -> Student Name can be maximum %d characters long.\n", NAME_LEN);
  printf(" -> Student Email can be maximum %d characters long and unique for "
         "every student.\n",
         EMAIL_LEN);
  printf(" -> Student Phone can be maximum %d characters long and unique for "
         "every student.\n",
         PHONE_LEN);
  printf(" -> Course code can be maximum %d characters long.\n", CODE_LEN);
  printf(" -> Course Name can be maximum %d characters long.\n\n",
         COURSE_NAME_LEN);

  printf(
      " ->> visit www.insideTheDiv.com for more projects like this. <<-\n\n");
}

void AboutUs(void) {
  printf("\n\t\t **** About US? ****\n\n");
  printf(" Some important notes to remember.\n");
  printf(" -> This is a simple student management system project.\n");
  printf(" -> You can modify the source code.\n");
  printf(" -> You can use this project only for personal purposes not for "
         "business.\n\n");
  printf(
      " ->> visit www.insideTheDiv.com for more projects like this. <<-\n\n");
}

void GoBackOrExit(void) {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF) {
  } // flush
  char Option = '\0';
  printf(" Go back(b)? or Exit(0)?: ");
  if (scanf(" %c", &Option) == 1) {
    if (Option == '0') {
      ExitProject();
    } else {
      ClearScreen();
    }
  } else {
    ClearScreen();
  }
}

void ExitProject(void) {
  ClearScreen();
  const char *ThankYou = " ========= Thank You =========\n";
  const char *SeeYouSoon = " ========= See You Soon ======\n";
  printf("%s%s", ThankYou, SeeYouSoon);
  exit(0);
}

void DataSeed(void) {
  // sample data (keeps within defined lengths)
  strncpy(Students[0].ID, "S-1", ID_LEN);
  strncpy(Students[0].Name, "Student 1", NAME_LEN);
  strncpy(Students[0].Phone, "016111111111", PHONE_LEN);
  strncpy(Students[0].Email, "student-1@gmail.com", EMAIL_LEN);
  Students[0].NumberOfCourse = 1;

  strncpy(Courses[0].StudentID, "S-1", ID_LEN);
  strncpy(Courses[0].Code, "CSE-1", CODE_LEN);
  strncpy(Courses[0].Name, "Course - 1", COURSE_NAME_LEN);

  strncpy(Students[1].ID, "S-2", ID_LEN);
  strncpy(Students[1].Name, "Student 2", NAME_LEN);
  strncpy(Students[1].Phone, "016111111112", PHONE_LEN);
  strncpy(Students[1].Email, "student-2@gmail.com", EMAIL_LEN);
  Students[1].NumberOfCourse = 2;

  strncpy(Courses[1].StudentID, "S-2", ID_LEN);
  strncpy(Courses[1].Code, "CSE-1", CODE_LEN);
  strncpy(Courses[1].Name, "Course - 1", COURSE_NAME_LEN);

  strncpy(Courses[2].StudentID, "S-2", ID_LEN);
  strncpy(Courses[2].Code, "CSE-2", CODE_LEN);
  strncpy(Courses[2].Name, "Course - 2", COURSE_NAME_LEN);

  strncpy(Students[2].ID, "S-3", ID_LEN);
  strncpy(Students[2].Name, "Student 3", NAME_LEN);
  strncpy(Students[2].Phone, "016111111113", PHONE_LEN);
  strncpy(Students[2].Email, "student-3@gmail.com", EMAIL_LEN);
  Students[2].NumberOfCourse = 3;

  strncpy(Courses[3].StudentID, "S-3", ID_LEN);
  strncpy(Courses[3].Code, "CSE-1", CODE_LEN);
  strncpy(Courses[3].Name, "Course - 1", COURSE_NAME_LEN);

  strncpy(Courses[4].StudentID, "S-3", ID_LEN);
  strncpy(Courses[4].Code, "CSE-2", CODE_LEN);
  strncpy(Courses[4].Name, "Course - 2", COURSE_NAME_LEN);

  strncpy(Courses[5].StudentID, "S-3", ID_LEN);
  strncpy(Courses[5].Code, "CSE-3", CODE_LEN);
  strncpy(Courses[5].Name, "Course - 3", COURSE_NAME_LEN);

  TotalStudents = 3;
  TotalCourse = 6;
}
