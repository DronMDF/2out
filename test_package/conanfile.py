from conans import ConanFile, CMake
import os

class OoutTestConan(ConanFile):
	settings = "os", "compiler", "build_type", "arch"
	generators = "cmake"

	def build(self):
		cmake = CMake(self)
		cmake.configure()
		cmake.build()

	def test(self):
		cmake = CMake(self)
		cmake.test()
