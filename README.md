# Factory Pattern in C Demonstration Application

This is a simple C demonstration application that showcases the use of the factory design pattern.

## Table of Contents

- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [Sample Application Execution](#sample-application-execution)

## Introduction

The application employs the factory design pattern to dynamically create a filesystem object using a factory method. It then performs dummy operations on the created filesystem, showcasing the flexibility of the pattern. Subsequently, the dynamically allocated memory associated with the filesystem object is freed when the application is deinitialised.

The factory design pattern is utilized to create instances of different filesystem types dynamically. This allows for the easy interchangeability of filesystem implementations. The example in this application demonstrates the usage of the NTFS filesystem type. However, it's possible to seamlessly exchange the NTFS filesystem type for FAT32 without any consequences.

## Project Structure

- **`main.c`**: The entry point of the application, initializing and running the demonstration.
- **`log.h`**: Header file defining a basic logging macro.
- **`filesystem.h`**: Header file containing the filesystem-related declarations and a generic filesystem API.
- **`filesystem.c`**: Implementation file for filesystem creation and operations.
- **`filesystem_ntfs.h`**: Header file specific to the NTFS filesystem type.
- **`filesystem_ntfs.c`**: Implementation file for the NTFS filesystem type.
- **`filesystem_fat32.h`**: Header file specific to the FAT32 filesystem type.
- **`filesystem_fat32.c`**: Implementation file for the FAT32 filesystem type.
- **`container_of.h`**: Header file defining a macro for obtaining a pointer to the containing structure.
- **`application.h`**: Header file for the main application structure.
- **`application.c`**: Implementation file for the main application, demonstrating the usage of the factory design pattern.

## Sample Application Execution

Below is a sample execution of the application, demonstrating the initialization, operation, and deinitialization process:

```
[2023-12-02 14:25:49 application_init]: Application initialising.    
[2023-12-02 14:25:49 application_init]: Application initialised.     
[2023-12-02 14:25:49 application_run]: Application running.
[2023-12-02 14:25:49 filesystem_ntfs_open_file]: Opening file (NTFS).
[2023-12-02 14:25:49 filesystem_ntfs_close_file]: Closing file (NTFS).
[2023-12-02 14:25:49 application_run]: Application ran.
[2023-12-02 14:25:49 application_deinit]: Application deinitialising. 
[2023-12-02 14:25:49 filesystem_ntfs_free]: Freeing filesystem (NTFS).
[2023-12-02 14:25:49 filesystem_ntfs_free]: Freed filesystem (NTFS).  
[2023-12-02 14:25:49 application_deinit]: Application deinitialised.
```

This section provides a glimpse into the flow of the application, its key steps and corresponding log entries.