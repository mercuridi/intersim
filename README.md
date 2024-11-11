# intersim
C++ fantasy world history simulator. Inspired by Dwarf Fortress' Legends Mode, developed for my own fantasy world called The Interim.
intersim will run on pure C++, ideally with minimal use of external libraries. If C++ becomes a limitation (most likely through memory safety issues), intersim will be ported to Rust under a new project, likely named intersim-rs.
intersim is planned only to be a CLI tool, but may be developed to feature a GUI in future.

This README was last edited at intersim v0.00.

## Initial Project Plan
Checkboxes indicate features considered complete.

### High Speed Global Simulation
- [ ] intersim, as a compiled C++ program, should be able to simulate a complex and deep world with hundreds (if not thousands) of years of rich history in a matter of minutes on reasonable hardware.
- [ ] intersim should feature multiple levels (at least 2) of "complexity", name pending. 
    - [ ] These depth levels should dictate the granularity of the world simulation; e.g. high depths should keep track of individual important figureheads in the world, while low levels only track the overarching state of large regions.
- [ ] The user should be able to set unique stopping points for history generation e.g. year reached, wars ended, etc.
- [ ] At any time, the system should allow the user to pause the generation of history, explore it, and then resume generation.
### Extreme Configurability
- [ ] All in-program data should come from config files exposed to the user.
- [ ] intersim should ship with a "default" configuration, along with a short guide on how to alter these configs so that the end user can use intersim for their own custom fantasy worlds.
- [ ] When writing a fantasy world, certain events can be set in stone. intersim should allow the user to specify certain events and the years they happen.
- [ ] intersim should support a configurable fantasy calendar.
- [ ] intersim should ship with a "config creator", a CLI tool that assists the user in making their desired config file.
### Random Events Grounded in Reality
- [ ] intersim should generate world history through a combination of randomness and known factors. 
    - [ ] Each entity in intersim should have an "opinions matrix" of that entity's attitudes towards different aspects of the world including economy, religion, military, and interpersonal history. This matrix should be used to determine the entity's feelings towards other entities, and should be used to determine the geopolitical state of the world.
- [ ] The random seed should be derived from the user configurations provided, creating a "canonical" history for that world's settings which can easily be generated again if the compressed world history file is lost. This feature should be easily disabled at the user's whim.
### Director Driven
- [ ] The course of history should be controlled in some degree by the "director", a subprogram that adapts to the state of the world and gently pushes wars to begin or end depending on how "busy" the world is. This concept of a director may evolve or simply be scrapped as development continues.
- [ ] The Director should also have its own configurations, e.g. allowing it to be more bloodthirsty or "protect" weaker nations from war.
### Sensible Warring
- [ ] Wars should begin based on the attitudes of regions to one another.
- [ ] Winners of wars should be determined based on a combination of randomness, military power, logistical sensibility, and economic prowess.
### Persistent Generations
- [ ] intersim should allow users to save a compressed world history file that can be opened later by intersim for further exploration.
### Future Plans
- intersim may be developed further by adding a GUI mode for exploration of the generated history.
- intersim may be developed further by incorporating a representation of a magic system.
