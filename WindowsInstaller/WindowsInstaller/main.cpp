#include <iostream>
#include <Windows.h>

#include "error_codes.h"
#include "exceptions.h"
#include "consts.h"
#include "Utils/configuration_parse.h"
#include "Utils/easylogging++.h"
#include "WindowsInstaller/WindowsInstaller.h"

INITIALIZE_EASYLOGGINGPP

/**
 * @argv[1] - Path of the configuration file
 */
int wmain(int argc, wchar_t* argv[], wchar_t* envp[])
{
	UNREFERENCED_PARAMETER(envp);

	if (VALID_NUMBER_OF_ARGUMENTS != argc) {
		LOG(FATAL) << "Invalid number of arguments was given";
		return INVALID_NUMBER_OF_ARGUMENTS;
	}

	try {

		LOG(INFO) << "Parsing the configuration";
		auto configuration = configuration_parse::parse_configuration(argv[1]);
		LOG(INFO) << "Configuration parsed successfully";

		auto installer = configuration.get<WindowsInstaller>();

		LOG(INFO) << "Starting Installation";
		installer.install();
		LOG(INFO) << "Installed Successfully";

		LOG(INFO) << "Commiting changes";
		installer.commit();
		LOG(INFO) << "Committed Successfully";
	}
	catch (const nlohmann::json::exception& json_exception) {
		LOG(FATAL) << "Failed to process the json configuration, " << json_exception.what();
		return JSON_CONFIGURATION_FAILURE;
	}
	catch (const FileException& file_exception) {
		LOG(FATAL) << file_exception.what();
		return FILE_IO_FAILURE;
	}
	catch (...) {
		LOG(FATAL) << "Failed running for unknown reason";
		return UNKNOWN_FAILURE_OCCURRED;
	}
	LOG(INFO) << "Finished Running Successfully";
	return INSTALLATION_SUCCESS;
}