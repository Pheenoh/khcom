.syntax unified
	.align 2, 0
	.global func_081205D8
	.thumb
	.thumb_func
	.type func_081205D8, %function
func_081205D8: @ 081205D8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r6, r1, #0x0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	cmp r4, #0x00
	beq _0812063C
	cmp r4, #0x10
	bls _081205EC
	movs r4, #0x10
_081205EC:
	ldr r0, _08120644 @ =0x03007FF0
	ldr r5, [r0, #0x00]
	ldr r1, [r5, #0x00]
	ldr r0, _08120648 @ =0x68736D53
	cmp r1, r0
	bne _0812063C
	adds r0, r1, #0x1
	str r0, [r5, #0x00]
	adds r0, r7, #0x0
	bl func_08120200
	str r6, [r7, #0x2C]
	strb r4, [r7, #0x08]
	movs r0, #0x80
	lsls r0, r0, #0x18
	str r0, [r7, #0x04]
	cmp r4, #0x00
	beq _08120620
	movs r1, #0x00
_08120612:
	strb r1, [r6, #0x00]
	subs r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r6, #0x50
	cmp r4, #0x00
	bne _08120612
_08120620:
	ldr r0, [r5, #0x20]
	cmp r0, #0x00
	beq _08120630
	str r0, [r7, #0x38]
	ldr r0, [r5, #0x24]
	str r0, [r7, #0x3C]
	movs r0, #0x00
	str r0, [r5, #0x20]
_08120630:
	str r7, [r5, #0x24]
	ldr r0, _0812064C @ =0x0811F7AD
	str r0, [r5, #0x20]
	ldr r0, _08120648 @ =0x68736D53
	str r0, [r5, #0x00]
	str r0, [r7, #0x34]
_0812063C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08120644: .4byte 0x03007FF0
_08120648: .4byte 0x68736D53
_0812064C: .4byte 0x0811F7AD
.syntax divided
