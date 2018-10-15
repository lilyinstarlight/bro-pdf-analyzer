
#include "Plugin.h"

namespace plugin { namespace Analyzer_PDF { Plugin plugin; } }

using namespace plugin::Analyzer_PDF;

plugin::Configuration Plugin::Configure()
	{
	plugin::Configuration config;
	config.name = "Analyzer::PDF";
	config.description = "<Insert description>";
	config.version.major = 0;
	config.version.minor = 1;
	return config;
	}
