.syntax unified
	.align 2, 0
	.global func_080A324C
	.thumb
	.thumb_func
	.type func_080A324C, %function
func_080A324C: @ 080A324C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	movs r4, #0x00
	ldr r5, _080A32C0 @ =0x0000010D
	adds r2, r7, #0x1
	ldr r3, _080A32C4 @ =0x0203A8C0
_080A325C:
	adds r0, r2, r4
	adds r1, r4, r3
	ldrb r1, [r1, #0x00]
	strb r1, [r0, #0x00]
	adds r4, #0x01
	cmp r4, r5
	ble _080A325C
	ldr r2, _080A32C8 @ =0x0203A080
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r4, _080A32CC @ =0x000003E7
_080A3274:
	ldrh r0, [r2, #0x00]
	strh r0, [r1, #0x00]
	adds r2, #0x02
	adds r1, #0x02
	subs r4, #0x01
	cmp r4, #0x00
	bne _080A3274
	movs r2, #0x8E
	lsls r2, r2, #0x04
	adds r5, r7, r2
	movs r6, #0x00
	ldr r0, _080A32D0 @ =0x02039DE0
	mov r8, r0
	movs r4, #0x02
_080A3290:
	mov r2, r8
	adds r1, r6, r2
	adds r0, r5, #0x0
	movs r2, #0xE0
	bl memcpy
	adds r5, #0xE0
	adds r6, #0xE0
	subs r4, #0x01
	cmp r4, #0x00
	bge _080A3290
	ldr r0, _080A32D4 @ =0x0203A858
	ldrh r1, [r0, #0x00]
	ldr r2, _080A32D8 @ =0x000008DE
	adds r0, r7, r2
	strh r1, [r0, #0x00]
	bl GetActiveDeckIndex
	strb r0, [r7, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080A32C0: .4byte 0x0000010D
_080A32C4: .4byte 0x0203A8C0
_080A32C8: .4byte 0x0203A080
_080A32CC: .4byte 0x000003E7
_080A32D0: .4byte 0x02039DE0
_080A32D4: .4byte 0x0203A858
_080A32D8: .4byte 0x000008DE
.syntax divided
