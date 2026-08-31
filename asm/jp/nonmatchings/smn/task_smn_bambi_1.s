.syntax unified
	.align 2, 0
	.global task_smn_bambi_1
	.thumb
	.thumb_func
	.type task_smn_bambi_1, %function
task_smn_bambi_1:
	.incbin "roms/B8CJ.gba", 0x420e0, 0x460
.syntax divided
