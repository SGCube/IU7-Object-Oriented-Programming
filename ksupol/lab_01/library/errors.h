#ifndef ERRORS_H
#define ERRORS_H

enum error_type {OK = 0, ErrorFileOpen = 1, ErrorFileRead, ErrorFileSave, ErrorFileName, ErrorAllocation, ErrorFree,
                ErrorModelInit, ErrorEdgesExist, ErrorNodesExist, ErrorAction, ErrorField};

const char* get_message(error_type error);

#endif // ERRORS_H

