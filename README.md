Project to practice programming.

Building a small sliding puzzle game.

Features:

-Selectable image

-Selectable size

That's it!

Aditionally, it is planned to add a verification to make any puzzle solvable.

Context: I believe the original project that I made in SDL was lost, but 
when it was completed, I run into the issue that some puzzles were impossible
to solve, as the final pieces were set in a way that they could not be properly
ordered.

For a long while, I didn't understand the reason, until I came across [this site](https://www.lukelavalva.com/theoryofsliding),
which explains on simple terms (simple for a mathematician, that is) why this
happens.

In another words, based on this information the plan is to include a verification
step, so that every randomly generated puzzle does indeed have a solution.
