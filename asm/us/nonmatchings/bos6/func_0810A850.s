.syntax unified
	.align 2, 0
	.global func_0810A850
	.thumb
	.thumb_func
	.type func_0810A850, %function
func_0810A850: @ 0810A850
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r7, r4, #0x0
	adds r7, #0x54
	movs r0, #0xB2
	lsls r0, r0, #0x01
	adds r5, r4, r0
	adds r0, r4, #0x0
	bl func_08109ECC
	adds r2, r0, #0x0
	movs r3, #0x00
	movs r6, #0x06
	b _0810A890
_0810A86C:
	ldrb r1, [r2, #0x00]
	movs r0, #0x0C
	ands r0, r1
	cmp r0, #0x00
	beq _0810A88E
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r2, #0x04]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r2, #0x06]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_0810A88E:
	adds r2, #0x0C
_0810A890:
	ldrb r1, [r2, #0x00]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0x00
	beq _0810A86C
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	lsrs r0, r0, #0x1F
	adds r1, r1, r0
	lsls r0, r6, #0x10
	asrs r2, r0, #0x10
	lsrs r0, r0, #0x1F
	adds r2, r2, r0
	asrs r1, r1, #0x01
	lsls r1, r1, #0x08
	ldr r0, [r4, #0x20]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r4, #0x24]
	str r0, [r7, #0x08]
	asrs r2, r2, #0x01
	lsls r2, r2, #0x08
	ldr r0, [r4, #0x28]
	adds r0, r0, r2
	str r0, [r7, #0x0C]
	adds r0, r4, #0x0
	bl func_08109EB0
	adds r2, r0, #0x0
	ldrh r0, [r2, #0x04]
	ldrh r1, [r2, #0x06]
	orrs r0, r1
	ldrh r1, [r2, #0x08]
	orrs r0, r1
	cmp r0, #0x00
	beq _0810A8FA
	movs r0, #0x04
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r4, #0x20]
	adds r0, r0, r1
	str r0, [r5, #0x04]
	movs r0, #0x06
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r5, #0x08]
	movs r0, #0x08
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r4, #0x28]
	b _0810A906
_0810A8FA:
	ldr r0, [r4, #0x20]
	str r0, [r5, #0x04]
	ldr r0, [r4, #0x24]
	str r0, [r5, #0x08]
	ldr r0, [r4, #0x28]
	ldr r1, _0810A910 @ =0xFFFFF400
_0810A906:
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0810A910: .4byte 0xFFFFF400
.syntax divided
