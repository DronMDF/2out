from conans import ConanFile, CMake

class OoutConan(ConanFile):
	name = "2out"
	version = "0.4"
	description = "Object oriented unit testing framework"
	license = "MIT"
	url = "https://dronmdf.github.io/2out/"

	settings = "os", "compiler", "build_type", "arch"
	options = {"shared": [True, False]}
	default_options = "shared=False"
	generators = "cmake"

	def source(self):
		self.run("git clone https://github.com/DronMDF/2out.git")

	def build(self):
		cmake = CMake(self)
		self.run('cmake 2out %s' % cmake.command_line)
		self.run("cmake --build . %s" % cmake.build_config)

	def package(self):
		self.copy("*.h", dst="include/2out", src="2out/2out")
		self.copy("*.so", dst="lib", keep_path=False)
		self.copy("*.a", dst="lib", keep_path=False)

	def package_info(self):
		self.cpp_info.libs = ["2out"]
