from conans import ConanFile, CMake
import os

# @todo #202 Conan.io test_project example was not linked
#  example link with -l2out, but test_runner link with ../2out/lib2out.a
#  This is not a problem, i try link test_runner with -l, and it passed.
#  May be problem in TextReport?

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
