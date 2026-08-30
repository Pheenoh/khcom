.syntax unified
	.align 2, 0
	.global task_poo_rabbit_3
	.thumb
	.thumb_func
	.type task_poo_rabbit_3, %function
task_poo_rabbit_3: @ 080CE6E4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CE702
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	adds r0, r4, #0x0
	adds r0, #0x4C
	bl func_08012304
_080CE702:
	adds r0, r4, #0x0
	adds r0, #0x38
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
