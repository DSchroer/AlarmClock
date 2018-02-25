env = Environment(
    CC = 'avr-gcc',
    CCFLAGS = '-Wall -Os -DF_CPU=1000000UL -mmcu=atmega32',
    LINKFLAGS = '-mmcu=atmega32')

env.Program('main.elf', [Glob('src/*.c'), Glob('src/lib/*.c')])
env.Command('main.hex', 'main.elf', 'avr-objcopy -j .text -j .data -O ihex $SOURCE $TARGET')
env.Command(None, 'main.hex', "avr-size $SOURCE")