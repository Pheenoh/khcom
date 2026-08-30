.syntax unified
	.align 2, 0
	.global task_poo_prize_1
	.thumb
	.thumb_func
	.type task_poo_prize_1, %function
task_poo_prize_1: @ 080D1D70
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, [r4, #0x7C]
	cmp r1, #0x00
	beq _080D1D88
	bl _call_via_r1
	ldr r0, [r4, #0x7C]
	cmp r0, #0x00
	beq _080D1D88
	movs r0, #0x01
	b _080D1D8A
_080D1D88:
	movs r0, #0x00
_080D1D8A:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
