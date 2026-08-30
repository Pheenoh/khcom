.syntax unified
	.align 2, 0
	.global func_080BB5E8
	.thumb
	.thumb_func
	.type func_080BB5E8, %function
func_080BB5E8: @ 080BB5E8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	movs r0, #0x02
	ldsh r1, [r4, r0]
	ldr r2, [r4, #0x08]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r1, [r4, r2]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	blt _080BB636
	movs r2, #0x00
	strh r2, [r4, #0x00]
	ldrh r0, [r4, #0x02]
	adds r0, #0x01
	strh r0, [r4, #0x02]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x04
	ldsh r1, [r4, r3]
	cmp r0, r1
	blt _080BB620
	strh r2, [r4, #0x02]
_080BB620:
	movs r1, #0x02
	ldsh r0, [r4, r1]
	lsls r2, r0, #0x02
	adds r2, r2, r0
	lsls r2, r2, #0x02
	ldr r1, [r4, #0x08]
	adds r1, r1, r2
	adds r1, #0x04
	adds r0, r5, #0x0
	bl func_080BB428
_080BB636:
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x01
	bl func_080BB588
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
