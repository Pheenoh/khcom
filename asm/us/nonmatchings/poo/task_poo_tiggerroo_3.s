.syntax unified
	.align 2, 0
	.global task_poo_tiggerroo_3
	.thumb
	.thumb_func
	.type task_poo_tiggerroo_3, %function
task_poo_tiggerroo_3: @ 080CED28
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080CED36
	bl func_080028C0
_080CED36:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CED48
	bl func_08002C10
	adds r0, r4, #0x0
	adds r0, #0x38
	bl func_08012304
_080CED48:
	adds r0, r4, #0x0
	adds r0, #0x94
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
