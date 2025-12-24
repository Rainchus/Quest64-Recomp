History of these ports. by Sonic Dreamcaster

You could say development started with [SF64DECOMP](https://github.com/sonicdcer/sf64). After working on [MMDECOMP](https://github.com/zeldaret/mm) and [SOTNDECOMP](https://github.com/Xeeynamo/sotn-decomp) for more than two years, I felt it was time to start something new, a project I had been searching for a long time, until I ultimately decided to start myself.

Our motivation for decompiling Star Fox 64 was to see, with our own eyes, how one of the greatest games ever made was constructed. Understanding how the game worked internally was our primary goal, especially given the involvement of Kazuaki Morita as the lead programmer. Both [PETRIE911] and I had already witnessed his engineering prowess through [OOTDECOMP](https://github.com/zeldaret/oot) and [MMDECOMP](https://github.com/zeldaret/mm), and we weren’t done peaking into this legend's programmer mind. His code is recognizable, characterized by massive switch statements and extensive use of work buffers, which also posed a unique challenge within the Nintendo 64 decompilation scene.

[SF64DECOMP](https://github.com/sonicdcer/sf64) was born September 19 of 2023, after achieving a matching disassembly with some help from [DECOMPALS](https://github.com/decompals) and [SPLAT](https://github.com/ethteck/splat), the decompilation effort began, led by [PETRIE911] and myself.

[ DECOMPALS SCREENSHOT HERE ]

January of 2024: 47.41% Matching functions
February of 2024: 73.51% Matching functions
March of 2024: 95.97% Matching functions

By February of 2024, we had more than 80% of the game code decompiled, with additional contributors joining the project:

* [KIRITO]
* [RYAN]
* [INSPECT]

These member additions came along with [KIRITO]'s brand new [TORCH], a tool that blessed the project with asset extraction capabilities.

April 1, 2024:
The entire game had been decompiled, with 100% of the assets extracted, 2,935 matching functions (99.46%), and 16 NON_MATCHING functions with equivalent C code. That same night, the first mini-build was born—codenamed “Lylat-64.” I couldn’t believe my eyes.

[ MINI BUILD PHOTO HERE ]

[LIBULTRASHIP] is an all-in-one N64 porting library, previously used for [SOH] and [2SHIP]. It uses [EMIL]’s Fast3D renderer for graphics and reimplements most of libultra’s functionality for modern platforms.

Using [KENIX]’s [LIBULTRASHIP], [KIRITO] was able to build the foundational base of today’s [STARSHIP] PC PORT.

Development continued for several months as we focused on stabilizing the game and resolving graphical issues. It wasn’t an easy path, but we were making steady progress.

Developing the port using this native approach helped us uncover issues in [SF64DECOMP](https://github.com/sonicdcer/sf64)
. Because Star Fox 64 uses segmented addresses for assets and overlapping overlays, having matching decompiled C code does not guarantee correctness. Asset linking was not always entirely accurate, even when the pointers referenced the correct memory addresses. Additionally, undefined behavior and bugs were discovered in both the engine and audio code—issues that needed to be fixed to ensure the game could run properly on a different system.

New challenges arose when running this big-endian 32-bit code on 64-bit little-endian systems, the most difficult being the audio driver. As a result, audio did not work until November 2024.

May 10, 2024:
[N64RECOMP] was released, alongside [ZELDA64RECOMP], a new N64 porting library that used a different approach: static recompilation. I was immediately curious and wondered how difficult it would be to get Star Fox 64 working with it. The benefits were clear—static recompilation meant I didn’t have to worry about 64-bit, little-endian issues, or the audio driver, since the recompiled code would reimplement the entire MIPS assembly of the ROM in a literal form of C code, even replicating the original game’s undefined behavior.

Another advantage was the ability to use the decompiled C code from [SF64DECOMP](https://github.com/sonicdcer/sf64) to write patches and quality-of-life enhancements. [WISEGUY]’s N64 thread implementation was also incredibly accurate, so I didn’t have to worry about that either. But what truly caught my attention was the graphics renderer that came with it.

[RT64] by [DARIOSAMO] is the most accurate HLE N64 renderer I’ve ever seen, and it includes an excellent graphics debugger, which is invaluable for graphics analysis.

Unfortunately, [N64RECOMP] wasn't ready for sf64 as it didn’t yet support overlapping overlays, but that wouldn’t be the case for long.

With [STARSHIP] stuck without audio and both [KIRITO] and I in a burnout state, I decided to focus on [SF64DECOMP](https://github.com/sonicdcer/sf64) documentation for the moment.

August 25, 2024:
[N64RECOMP] was finally ready for Star Fox 64. Overlapping overlay support had been implemented, and I was eager to give it a try.
[SF64RECOMP] was born. The game was already in great shape, but the most important detail stood out: it had perfect sound, out of the box!
Much like Starship, it still needed fixes for proper widescreen and interpolation. However, RT64’s automatic interpolation system handled this game surprisingly well.

With two ports booting and partially functional, I had to decide which technology to use, but it wasn’t an easy choice.

## The pros and cons:
[STARSHIP] - [LIBULTRASHIP] - [FAST3D]:

# Pros:
* A native approach such as this provides full debugging capabilities. Breakpointing through readable code and hot-reloading changes was incredibly handy, not only for fixing crashes or logic issues, but also for developing quality-of-life enhancements or mods in real time. It also proved invaluable for code documentation; such powerful tools cannot be overlooked.
* Fixing [SF64DECOMP](https://github.com/sonicdcer/sf64) asset and data references was extremely important for preservation, and this approach significantly aided that effort.
* Modding: [LIBULTRASHIP] asset importer supports asset replacement out of the box. By simply modifying the asset files, modders can swap textures, models, or even sounds easily.
* Supports four controllers out of the box, so multiplayer is already possible.

# Cons:
* Audio still needed to be fixed.
* Fast3D was developed with SM64 in mind. While it works reasonably well for SF64, it lacks some effects and has inaccuracies and graphical issues that still need to be addressed.
* Modding: Due to memory layout differences, function hooking was difficult to achieve without cluttering the code. I prefer keeping the code as clean as possible to maintain proper synchronization with the decompilation project.
* Matrix interpolation must be implemented manually and runs entirely in software.

[SF64RECOMP] - [N64RECOMP] - [RT64]

# Pros
* Static recompilation replicates undefined behaviour.
* The memory layout matches the N64, allowing modding closer to traditional ROM-hacking practices. Function hooking is easy.
* Audio works out of the box.
* RT64 is way more accurate and performant, has an automatic Matrix Interpolation system, supports a variety of Extended GBI commands for handling both interpolated matrices as well as widescreen fixes, and it has an excellent debugger.

# Cons
* The N64 memory layout comes with limitations: arrays are not resizable, so some types of modding require extra effort, though it is still possible.
* Breakpoints are only usable within recompiled C code, which is harder to read. Hot-reloading is not available, so the game must be recompiled after each change.
* It does not yet support four controllers, so multiplayer is currently unavailable.

## My Philosophy

After careful consideration, I decided that the best course of action is to pursue both approaches, and here’s why:
We must remember that this project is ultimately about game preservation. Having both ports available allows them to evolve along different paths. Some developers prefer fully native, instantly modifiable code, while others prioritize graphical accuracy, simple function hooking, or other features. There is no perfect approach, and I firmly believe users and developers should have both options.

Developing both ports also allowed me to leverage all the tools at my disposal to get the best results. For example, I used Starship and Visual Studio’s debugger with hot reload to reprogram all range floors, as well as RT64’s debugger to identify actors for documentation and interpolation fixes.


From September to December 2024, both ports were developed in parallel, incorporating numerous interpolation and widescreen quality-of-life improvements. Initially planned for a December release, with Starship slightly ahead in development, minor refinements continued on the recompiled version. 

December 22, 2024:
The first version of [STARSHIP] releases.

After careful consideration, I decided to delay the recompiled port release to allow time for features that would set it apart from Starship, such as the modding framework or ray tracing support.

New Features & Improvements were added throughout 2025 to both ports.

May 4, 2025:
The first version of [WISEGUY]’s Modding Framework was released alongside [ZELDA64RECOMP] v1.2.0 and is now ready to be tested with [SF64RECOMP].

May 25, 2025:
The second version of [STARSHIP] was released, introducing many new features and improvements, some of which were also developed and carried over to [SF64RECOMP] for a future release.
