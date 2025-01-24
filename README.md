# Computer Networks - Data Link Protocol (First Project)

> Curricular Unit: [Computer Networks - 2024/25 1S](https://sigarra.up.pt/feup/en/UCURR_GERAL.FICHA_UC_VIEW?pv_ocorrencia_id=541890)<br>
> Faculty: [FEUP](https://sigarra.up.pt/feup/en/web_page.Inicial)<br>
> Professor: [Helder Fontes](https://sigarra.up.pt/feup/en/func_geral.formview?p_codigo=682981)<br>
> Authors: [Bruno Oliveira](https://github.com/Process-ing), [Rodrigo Silva](https://github.com/racoelhosilva)<br>
> Final Grade: 20.0/20

## Description

The objective of this project is to implement a data link protocol for communication between two Linux computers, connected through a serial port, along with a basic application protocol for file transfer between the two computers.

The project involved the use of Linux drivers for sending bits through the serial port, which the Data Link Layer used for establishing a reliable communication, using a basic XOR based error verification and Stop and Wait ARQ. Then, the Application Layer used the Data Link Layer to send files between the two computers.

It was also an objective to measure statistics about the protocol, such as the number of retransmissions and the protocol efficiency, for varying frame sizes and Bit Error Ratios, which are all documented on the report.

## Tips and Tricks (for anyone doing a similar project)

- Against the rave of doing extremely efficient code, this project only focuses on implementing the protocol correctly and accurately. If you find your code runs slower than most, don't worry, the most important thing is that it works, without bugs and according to the specifications. For context, our code is on the slower projects (takes ~11 seconds to transmit the penguin, while most take ~10 seconds), and we got full marks.
- **Do not use the heap**! Most people that use `malloc` and such later find memory related issues (especially heap buffer overflows). If you are not mindful of this, you will be lucky if something bad does not happen in your demonstration... You absolutely don't need to use dynamically allocated memory in this project, so don't use it! Define a maximum buffer size for each buffer and allocate it on the stack. To be extra sure that no memory errors occur, use the address sanitizer and undefined behavior sanitizer (`-g -fsanitize=address -fsanitize=undefined`) when compiling (but remove them when submitting, of course).
- In our project, we decided to divide the code into multiple logical units separated into files, going against what most people do. This is something I recommend, as it makes the code much more organized and easier to understand.
- As you may see in the `state.h` file, our state machine for reading I frames got pretty big because we included the byte stuffing logic into it (i.e. the `DATA_` states). Although this isn't necessarily bad, another viable approach would be to store the raw data inside the buffer as the packet is read, and then destuff it using an auxiliary function (and yes, it will be probably faster, as there are less verifications). I would recommend first trying this approach, and doing what we did if you find the results are too bad.
- \[Most important for last\] If you can, **try to have the code ready on the week before the demonstration**. It is absolutely a cheat code! Since it only matters if the code works in the computers at the lab, you will be extra sure that your code does not face problems when compiling on them. There are some libraries (UNIX and BSD related) that most Linux distributions offer that GCC on those computers does not support. This will make sure you do not face any compilation error during the presentation. If your professor is nice enough (like ours), you can even offer to do the presentation on the week before. Not only you do not need to worry about it later, but, in case something goes wrong, you can just fix it next week!