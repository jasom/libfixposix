/*******************************************************************************/
/* Permission is hereby granted, free of charge, to any person or organization */
/* obtaining a copy of the software and accompanying documentation covered by  */
/* this license (the "Software") to use, reproduce, display, distribute,       */
/* execute, and transmit the Software, and to prepare derivative works of the  */
/* Software, and to permit third-parties to whom the Software is furnished to  */
/* do so, all subject to the following:                                        */
/*                                                                             */
/* The copyright notices in the Software and this entire statement, including  */
/* the above license grant, this restriction and the following disclaimer,     */
/* must be included in all copies of the Software, in whole or in part, and    */
/* all derivative works of the Software, unless such copies or derivative      */
/* works are solely in the form of machine-executable object code generated by */
/* a source language processor.                                                */
/*                                                                             */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    */
/* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT   */
/* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE   */
/* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, */
/* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER */
/* DEALINGS IN THE SOFTWARE.                                                   */
/*******************************************************************************/

#pragma once

#include <libfixposix/aux.h>

CPLUSPLUS_GUARD

#include <unistd.h>

#include <sys/stat.h>
#include <stdbool.h>
#include <inttypes.h>

off_t lfp_lseek(int fd, off_t offset, int whence);

int lfp_pipe(int pipefd[2], uint64_t flags);

ssize_t lfp_pread(int fd, void *buf, size_t count, off_t offset);

ssize_t lfp_pwrite(int fd, const void *buf, size_t count, off_t offset);

int lfp_truncate(const char *path, off_t length);

int lfp_ftruncate(int fd, off_t length);

int lfp_stat(const char *path, struct stat *buf);

int lfp_fstat(int fd, struct stat *buf);

int lfp_lstat(const char *path, struct stat *buf);

int lfp_fd_is_open(int fd);

bool lfp_isreg(mode_t mode);

bool lfp_isdir(mode_t mode);

bool lfp_ischr(mode_t mode);

bool lfp_isblk(mode_t mode);

bool lfp_isfifo(mode_t mode);

bool lfp_islnk(mode_t mode);

bool lfp_issock(mode_t mode);

char* lfp_getpath(char *const envp[]);

int lfp_execve(const char *path, char *const argv[], char *const envp[])
    __attribute__((nonnull (1)));

int lfp_execvpe(const char *file, char *const argv[], char *const envp[])
    __attribute__((nonnull (1)));

END_CPLUSPLUS_GUARD
