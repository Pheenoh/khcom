.syntax unified
	.align 2, 0
	.global task_poo_honeycomb_3
	.thumb
	.thumb_func
	.type task_poo_honeycomb_3, %function
task_poo_honeycomb_3: @ 080CFC90
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CFCA6
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
_080CFCA6:
	adds r0, r4, #0x0
	adds r0, #0x9C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CFCB8
	adds r0, r4, #0x0
	adds r0, #0x38
	bl func_08012304
_080CFCB8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
