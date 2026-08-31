.syntax unified
	.align 2, 0
	.global task_smn_tinkeff_2
	.thumb
	.thumb_func
	.type task_smn_tinkeff_2, %function
task_smn_tinkeff_2:
	.incbin "roms/B8CJ.gba", 0x43088, 0x60
.syntax divided
