## Demo of DLL built on VS 2017 which exposes it's function to external FFIs (such as lisp's CFFI) using libnoise as example
### Implementation notes
* In project settings, make sure that the following are set
	* Config is release x64 (or x86 if your machine is x86)
	* Linker -> Debugging -> Generate Debug Info is set to NO
		* Without this, the build DLL has mangled names which make it impossible to call what you want from other projects.
	* Include directory is set to point to the include directory for libnoise
	* Additional dependencies (in Linker -> Input) specifies the .lib file for libnoise (MUST BE FOR SAME ARCHITECTURE AS CURRENT MACHINE)! I believe that the version of libnoise distributed on their webiste is x86 so I had to download the sources and build as x64 release.
	* exported functions in this library must be of the format
	  ```c++
	  extern "C" RETURN_TYPE __declspec(dllexport) FUNCTION_NAME() {
	  ```
	  (or be defined within an `extern "C"` block)
* since this is a VC++ project, I don't assume that it will work at all on linux or macOS without some level of translation. No effort was made to make this compatible with non-Windows since it was a demo for Windows in the first place.
* when project is configured as defined above (although it should be already), build it and copy the dll in the output folder to wherever you want to use it.