.syntax unified
	.align 2, 0
	.global func_08003598
	.thumb
	.thumb_func
	.type func_08003598, %function
func_08003598: @ 08003598
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	ldrh r6, [r4, #0x00]
	adds r4, #0x02
	movs r7, #0x00
	movs r5, #0x00
	cmp r7, r6
	bcs _080035C2
_080035A8:
	ldrh r0, [r4, #0x00]
	ldrh r1, [r4, #0x02]
	bl func_08001DB0
	adds r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r4, #0x06
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, r6
	bcc _080035A8
_080035C2:
	lsls r0, r7, #0x15
	lsrs r0, r0, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
