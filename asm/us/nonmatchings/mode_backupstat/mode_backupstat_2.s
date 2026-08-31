.syntax unified
	.align 2, 0
	.global mode_backupstat_2
	.thumb
	.thumb_func
	.type mode_backupstat_2, %function
mode_backupstat_2: @ 08109AA0
	push {lr}
	bl func_080609A0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
