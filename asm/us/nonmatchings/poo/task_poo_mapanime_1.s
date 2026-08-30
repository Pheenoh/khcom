.syntax unified
	.align 2, 0
	.global task_poo_mapanime_1
	.thumb
	.thumb_func
	.type task_poo_mapanime_1, %function
task_poo_mapanime_1: @ 080CD160
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	movs r2, #0x00
	movs r7, #0x00
	adds r4, r6, #0x0
	movs r5, #0x00
_080CD16C:
	adds r0, r6, #0x0
	adds r0, #0x08
	adds r0, r0, r5
	ldr r1, [r0, #0x00]
	adds r0, r4, #0x0
	bl func_080DDDEC
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r4, #0x0C
	adds r5, #0x0C
	adds r7, #0x01
	cmp r7, #0x01
	bls _080CD16C
	movs r0, #0x01
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
