.syntax unified
	.align 2, 0
	.global task_poo_honey_3
	.thumb
	.thumb_func
	.type task_poo_honey_3, %function
task_poo_honey_3: @ 080CD108
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CD12E
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	adds r0, r4, #0x0
	adds r0, #0x74
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0xD0
	bl func_080CCBD4
_080CD12E:
	adds r0, r4, #0x0
	adds r0, #0xF4
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
