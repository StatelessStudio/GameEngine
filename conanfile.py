from conans import ConanFile, CMake


class SsgeConan(ConanFile):
    name = "ssge"
    version = "0.0.0"
    license = "MIT"
    author = "Stateless Studio"
    url = "https://github.com/StatelessStudio/GameEngine"
    description = "Open Source C++ GameEngine managed by Conan"
    topics = ("3d", "game", "engine", "graphics", "sound", "physics", "networking")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"
    exports_sources = "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include/SSGE", src="src")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["ssge"]
