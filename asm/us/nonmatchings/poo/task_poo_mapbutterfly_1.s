.syntax unified
	.align 2, 0
	.global task_poo_mapbutterfly_1
	.thumb
	.thumb_func
	.type task_poo_mapbutterfly_1, %function
task_poo_mapbutterfly_1: @ 080D2690
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x34
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D26B0
	ldr r0, [r4, #0x2C]
	subs r0, #0x80
	str r0, [r4, #0x2C]
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	str r0, [r4, #0x08]
	movs r0, #0x01
	b _080D26B2
_080D26B0:
	movs r0, #0x00
_080D26B2:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
