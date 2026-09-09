.syntax unified
	.align 2, 0
	.global func_0801AF4C
	.thumb
	.thumb_func
	.type func_0801AF4C, %function
func_0801AF4C: @ 0801AF4C
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	ldr r1, _0801AFE4 @ =0x02039B84
	mov r9, r1
	ldr r2, [r1, #0x00]
	mov r8, r2
	ldr r1, [r2, #0x68]
	ldr r2, [r2, #0x6C]
	ldr r3, _0801AFE8 @ =0x00080000
	ldr r4, _0801AFEC @ =0x00000000
	orrs r1, r3
	ldr r5, _0801AFF0 @ =0x40000000
	ldr r6, _0801AFF4 @ =0x00000000
	adds r3, r1, #0x0
	orrs r3, r5
	adds r4, r2, #0x0
	ldr r5, _0801AFF8 @ =0x00000000
	ldr r6, _0801AFFC @ =0x00000002
	adds r1, r3, #0x0
	orrs r2, r6
	mov r3, r8
	str r1, [r3, #0x68]
	str r2, [r3, #0x6C]
	bl func_0801C830
	ldr r2, _0801B000 @ =0x09D6F60C
	ldr r0, _0801B004 @ =0x09D6F744
	ldrh r1, [r0, #0x1C]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	movs r1, #0x0C
	bl m4aMPlayFadeOut
	movs r0, #0x02
	movs r1, #0x14
	bl func_08006120
	bl func_080063A8
	mov r1, r9
	ldr r0, [r1, #0x00]
	adds r0, #0x80
	bl ListPoolFirst
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0801AFCC
	movs r5, #0x02
_0801AFB6:
	adds r0, r2, #0x0
	adds r0, #0xC4
	ldrh r1, [r0, #0x00]
	orrs r1, r5
	strh r1, [r0, #0x00]
	subs r0, #0x0C
	bl ListPoolNext
	adds r2, r0, #0x0
	cmp r2, #0x00
	bne _0801AFB6
_0801AFCC:
	ldr r0, _0801AFE4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xEE
	movs r1, #0x00
	strb r1, [r0, #0x00]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801AFE4: .4byte 0x02039B84
_0801AFE8: .4byte 0x00080000
_0801AFEC: .4byte 0x00000000
_0801AFF0: .4byte 0x40000000
_0801AFF4: .4byte 0x00000000
_0801AFF8: .4byte 0x00000000
_0801AFFC: .4byte 0x00000002
_0801B000: .4byte 0x09D6F60C
_0801B004: .4byte 0x09D6F744
.syntax divided
