from conans import ConanFile, CMake
import os

class OoutTestConan(ConanFile):
	settings = "os", "compiler", "build_type", "arch"
	generators = "cmake"

	def build(self):
		cmake = CMake(self)
		cmake.configure(source_dir=self.conanfile_directory, build_dir="./")
		cmake.build()

	def test(self):
		os.chdir("bin")
		self.run(".%sexample" % os.sep)
