.syntax unified
	.align 2, 0
	.global func_0802F208
	.thumb
	.thumb_func
	.type func_0802F208, %function
func_0802F208: @ 0802F208
	push {r4, r5, lr}
	ldr r4, _0802F254 @ =0x0203492C
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0802F24C
	ldr r3, _0802F258 @ =0x02034930
	ldr r1, _0802F25C @ =0x0813C7D8
	ldr r2, _0802F260 @ =0x0203492E
	movs r5, #0x00
	ldsh r0, [r2, r5]
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x0C
	ldr r1, [r3, #0x00]
	subs r0, r0, r1
	asrs r0, r0, #0x03
	adds r1, r1, r0
	str r1, [r3, #0x00]
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	strh r0, [r2, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1F
	bls _0802F24C
	movs r0, #0x00
	strb r0, [r4, #0x00]
	movs r1, #0x00
	str r1, [r3, #0x00]
	ldr r0, _0802F264 @ =0x02039B84
	ldr r0, [r0, #0x00]
	strb r1, [r0, #0x18]
_0802F24C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0802F254: .4byte 0x0203492C
_0802F258: .4byte 0x02034930
_0802F25C: .4byte 0x0813C7D8
_0802F260: .4byte 0x0203492E
_0802F264: .4byte 0x02039B84
.syntax divided
