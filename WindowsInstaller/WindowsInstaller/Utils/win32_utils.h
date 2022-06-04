#pragma once


#include <Windows.h>
#include <string>
#include <vector>


namespace win32_utils
{
	HANDLE create_file(const std::string& file_path, uint32_t desired_access, uint32_t creation_disposition,
		uint32_t flags_and_attributes);

	int get_file_size(HANDLE file_handle);

	void copy_file(const std::string& file_path, const std::string& target_directory, bool fail_if_exists);

	std::vector<char> read_file(HANDLE file_handle, uint32_t number_of_bytes_to_read);

	void delete_file(const std::string& file_path);

	std::string path_combine(const std::string& first_path, const std::string& second_path);

	void close_handle(HANDLE file_handle);

}
