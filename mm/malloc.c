// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	struct mem_list *start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	int ret = mem_list_add(start, size);

	if(ret == -1) {
		return NULL;
	}

	return (void*)start;
}

void *calloc(size_t nmemb, size_t size)
{
	struct mem_list *start = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	int ret = mem_list_add(start, start->len);

	if(ret == -1) {
		return NULL;
	}

	return (void*)start;
}

void free(void *ptr)
{
	struct mem_list *start = mem_list_find(ptr);

	if(start == NULL)
		return;

	int ret = munmap(ptr, start->len);

	if(ret < 0)
		return;

	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	struct mem_list *start = mem_list_find(ptr);
	void *new_address = mremap(ptr, start->len, size, 0);

	mem_list_add(new_address, size);

	return new_address;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *address = realloc(ptr, nmemb * size);

	return address;
}
