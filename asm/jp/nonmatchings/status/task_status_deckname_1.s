.syntax unified
	.align 2, 0
	.global task_status_deckname_1
	.thumb
	.thumb_func
	.type task_status_deckname_1, %function
task_status_deckname_1:
	.incbin "roms/B8CJ.gba", 0xd7e24, 0x4
.syntax divided
