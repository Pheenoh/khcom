.syntax unified
	.align 2, 0
	.global func_0800E0D0
	.thumb
	.thumb_func
	.type func_0800E0D0, %function
func_0800E0D0: @ 0800E0D0
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r5, _0800E158 @ =0x02039B84
	ldr r3, [r5, #0x00]
	adds r2, r3, #0x0
	adds r2, #0xEC
	ldr r1, _0800E15C @ =0x09EDA4EC
	ldr r0, [r4, #0x3C]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r1, [r2, #0x00]
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	strh r1, [r2, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x3C
	ldr r0, [r3, #0x78]
	cmp r0, r1
	bne _0800E0FA
	movs r0, #0x00
	str r0, [r3, #0x78]
_0800E0FA:
	adds r0, r1, #0x0
	bl func_0801B7D8
	ldr r5, [r5, #0x00]
	mov r12, r5
	mov r0, r12
	adds r0, #0xEE
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800E138
	movs r0, #0x90
	lsls r0, r0, #0x01
	add r0, r12
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	bgt _0800E138
	mov r2, r12
	ldr r0, [r2, #0x7C]
	movs r1, #0x2C
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	ble _0800E138
	ldr r0, [r2, #0x68]
	ldr r1, [r2, #0x6C]
	ldr r2, _0800E160 @ =0x00000000
	ldr r3, _0800E164 @ =0x00000002
	orrs r1, r3
	mov r2, r12
	str r0, [r2, #0x68]
	str r1, [r2, #0x6C]
_0800E138:
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x08]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x28
	bl TaskPoolDestroy
	pop {r4, r5}
	pop {r0}
	bx r0
_0800E158: .4byte 0x02039B84
_0800E15C: .4byte 0x09EDA4EC
_0800E160: .4byte 0x00000000
_0800E164: .4byte 0x00000002
.syntax divided
