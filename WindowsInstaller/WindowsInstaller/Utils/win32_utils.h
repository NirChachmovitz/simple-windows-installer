#pragma once


#include <Windows.h>
#include <string>
#include <vector>

/**
 * A namespace for supplying all the winapi utils, for a more convenient exception handling
 */
namespace win32_utils
{
	/**
	 * @brief Creates or opens a file or I/O device.
	 * @param[in] file_path - the path to the file
	 * @param[in] desired_access - the requested access to the file or device
	 * @param[in] creation_disposition - an action to take on a file or device that exists or does not exist
	 * @param[in] flags_and_attributes - the file or device attributes and flags
	 * @returns a handle to the file
	 */
	HANDLE create_file(const std::wstring& file_path, uint32_t desired_access, uint32_t creation_disposition,
		uint32_t flags_and_attributes);

	/**
	 * @brief returns the size of the file
	 * @param[in] file_handle - handle to the file
	 */
	int get_file_size(HANDLE file_handle);

	/**
	 * @brief copies an existing file to a new file.
	 * @param[in] file_path - the name of an existing file.
	 * @param[in] new_file_path - the name of the new file.
	 * @param[in] fail_if_exists - true if existence will fail, false otherwise
	 */
	void copy_file(const std::wstring& file_path, const std::wstring& new_file_path, bool fail_if_exists);

	/**
	 * @brief reads data from the specified file or input/output (I/O) device.
	 * @param[in] file_handle - a handle to the file
	 * @param[in] number_of_bytes_to_read - number of bytes to read from the file
	 * @returns a vector of bytes with the data read
	 */
	std::vector<std::byte> read_file(HANDLE file_handle, uint32_t number_of_bytes_to_read);

	/**
	 * @brief writes data to the specified file or input/output (I/O) device.
	 * @param[in] file_handle - a handle to the file
	 * @param[in] buffer - buffer to be written to the file
	 */
	void write_file(HANDLE file_handle, std::vector<std::byte> buffer);

	/**
	 * @brief delete a file from the disk
	 * @param[in] file_path - a path to the file to be deleted
	 */
	void delete_file(const std::wstring& file_path);

	/**
	 * @brief concatenates two strings that represent properly formed paths into one path
	 * @param[in] first_path - first path
	 * @param[in] second_path - second path
	 */
	std::wstring path_combine(const std::wstring& first_path, const std::wstring& second_path);

	/**
	 * @brief closes the handle
	 * @param[in] file_handle - a handle to the file
	 */
	void close_handle(HANDLE file_handle);

}
