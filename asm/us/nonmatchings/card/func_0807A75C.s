.syntax unified
	.align 2, 0
	.global func_0807A75C
	.thumb
	.thumb_func
	.type func_0807A75C, %function
func_0807A75C: @ 0807A75C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	movs r4, #0x00
	adds r2, r6, #0x0
	adds r2, #0xB9
	ldrb r0, [r2, #0x00]
	cmp r4, r0
	bcs _0807A790
	adds r3, r6, #0x0
	adds r3, #0x28
	movs r5, #0x21
	negs r5, r5
_0807A778:
	lsls r0, r4, #0x02
	adds r0, r3, r0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x78]
	ands r0, r5
	str r0, [r1, #0x78]
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldrb r1, [r2, #0x00]
	cmp r4, r1
	bcc _0807A778
_0807A790:
	movs r4, #0x00
	adds r7, r6, #0x0
	adds r7, #0xC9
_0807A796:
	lsls r0, r4, #0x04
	adds r0, #0x54
	adds r0, r6, r0
	bl func_08000C8C
	adds r1, r0, #0x0
	adds r4, #0x01
	cmp r1, #0x00
	beq _0807A7C0
	movs r5, #0x21
	negs r5, r5
_0807A7AC:
	ldr r0, [r1, #0x78]
	ands r0, r5
	str r0, [r1, #0x78]
	adds r0, r1, #0x0
	adds r0, #0x64
	bl func_08000CD4
	adds r1, r0, #0x0
	cmp r1, #0x00
	bne _0807A7AC
_0807A7C0:
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x03
	bls _0807A796
	ldr r0, _0807A804 @ =0x02039DD4
	mov r8, r0
	ldr r4, [r0, #0x00]
	adds r1, r4, #0x0
	adds r1, #0xCC
	movs r6, #0x00
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r0, _0807A808 @ =0x02039B84
	ldr r5, [r0, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	movs r2, #0x20
	movs r3, #0x00
	orrs r0, r2
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
	adds r4, #0xEA
	strb r6, [r4, #0x00]
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r0, #0xE3
	strb r6, [r0, #0x00]
	movs r0, #0x01
	strb r0, [r7, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0807A804: .4byte 0x02039DD4
_0807A808: .4byte 0x02039B84
.syntax divided
