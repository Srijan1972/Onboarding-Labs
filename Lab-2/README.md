# Week 2 Lab: System Verilog

- Exhaustive testing is used to provide 100% mathematical certainty. If a design passes exhaustive testing, it is guaranteed to be correct. However, as input(s) grow, the number of states to explore explodes, for example for a 64-bit input, $2^{64}$ inputs need to be explored which is not possible.
- Sampled testing is used when one knows of certain important inputs and only desires to test those inputs. This method is efficient and predictable, however, it leaves blind spots for unexpected inputs.
- Random testing is used to test many combinations of inputs that a human designer may not think of. This method is good at finding errors and easier to implement, however tests run may be redundant and errors are difficult to reproduce.
