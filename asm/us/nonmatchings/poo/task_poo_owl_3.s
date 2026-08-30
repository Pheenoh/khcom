.syntax unified
	.align 2, 0
	.global task_poo_owl_3
	.thumb
	.thumb_func
	.type task_poo_owl_3, %function
task_poo_owl_3: @ 080CE2A0
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CE2B6
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
_080CE2B6:
	adds r0, r4, #0x0
	adds r0, #0x34
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
