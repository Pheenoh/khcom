.syntax unified
	.align 2, 0
	.global func_080D58AC
	.thumb
	.thumb_func
	.type func_080D58AC, %function
func_080D58AC: @ 080D58AC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r2, _080D58EC @ =0x0203C4B4
	ldr r1, [r2, #0x00]
	subs r3, r3, r5
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x03
	adds r0, #0x20
	adds r1, #0xB2
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r7, r2, #0x0
	cmp r0, #0x9F
	bgt _080D58F0
	movs r2, #0x00
	ldsh r0, [r1, r2]
	movs r1, #0xA0
	subs r1, r1, r0
	lsrs r0, r1, #0x1F
	adds r1, r1, r0
	lsls r1, r1, #0x0F
	lsrs r3, r1, #0x10
	b _080D58F2
_080D58EC: .4byte 0x0203C4B4
_080D58F0:
	movs r3, #0x00
_080D58F2:
	ldr r2, [r7, #0x00]
	subs r1, r6, r4
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, #0x20
	adds r2, #0xB0
	strh r0, [r2, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xEF
	bgt _080D591C
	movs r1, #0x00
	ldsh r0, [r2, r1]
	movs r1, #0xF0
	subs r1, r1, r0
	lsrs r0, r1, #0x1F
	adds r1, r1, r0
	lsls r1, r1, #0x0F
	lsrs r1, r1, #0x10
	b _080D591E
_080D591C:
	movs r1, #0x00
_080D591E:
	ldr r2, [r7, #0x00]
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsls r0, r0, #0x03
	subs r0, r0, r1
	adds r1, r2, #0x0
	adds r1, #0xAC
	strh r0, [r1, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsls r0, r0, #0x03
	subs r0, r0, r3
	adds r2, #0xAE
	strh r0, [r2, #0x00]
	bl func_080D54FC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
