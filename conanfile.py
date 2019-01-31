from conans import ConanFile, CMake, tools

class OoutConan(ConanFile):
	name = "2out"
	version = "0.6"
	description = "Object oriented unit testing framework"
	license = "MIT"
	url = "https://dronmdf.github.io/2out/"

	settings = "os", "compiler", "build_type", "arch"
	options = {"shared": [True, False]}
	default_options = "shared=False"
	generators = "cmake"

	def source(self):
		self.run("git clone https://github.com/DronMDF/2out.git .")
		self.run("git checkout v%s" % self.version)
		tools.replace_in_file(
			"CMakeLists.txt",
			"ENABLE_TESTING()",
			'\n'.join((
				"include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)",
				"conan_basic_setup()",
				"ENABLE_TESTING()"
			))
		)

	def build(self):
		cmake = CMake(self)
		cmake.configure()
		cmake.build()

	def package(self):
		self.copy("*.h", dst="include/2out", src="2out")
		self.copy("*.so", dst="lib", keep_path=False)
		self.copy("*.a", dst="lib", keep_path=False)

	def package_info(self):
		self.cpp_info.libs = ["2out"]
