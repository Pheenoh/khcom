.syntax unified
	.align 2, 0
	.global task_status_deckname_3
	.thumb
	.thumb_func
	.type task_status_deckname_3, %function
task_status_deckname_3: @ 080D7E34
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x0A
	bl func_08065AE0
	ldr r0, [r4, #0x50]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
