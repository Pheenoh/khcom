.syntax unified
	.align 2, 0
	.global task_bos_boogie_knifereader_1
	.thumb
	.thumb_func
	.type task_bos_boogie_knifereader_1, %function
task_bos_boogie_knifereader_1:
	.incbin "roms/B8CJ.gba", 0xdb598, 0x10c
.syntax divided
