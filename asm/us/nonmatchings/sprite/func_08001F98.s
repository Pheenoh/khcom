.syntax unified
	.align 2, 0
	.global func_08001F98
	.thumb
	.thumb_func
	.type func_08001F98, %function
func_08001F98: @ 08001F98
	push {r4, r5, r6, lr}
	bl func_08001EF8
	ldr r4, _08002040 @ =0x030074C8
	ldr r0, [r4, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x05
	adds r0, r0, r1
	bl func_08000BA4
	adds r6, r4, #0x0
	movs r4, #0x00
	movs r5, #0x7F
_08001FB2:
	ldr r1, [r6, #0x00]
	adds r2, r1, r4
	adds r0, r2, #0x0
	adds r0, #0x0C
	movs r3, #0xC0
	lsls r3, r3, #0x05
	adds r1, r1, r3
	bl func_08000BB0
	adds r4, #0x30
	subs r5, #0x01
	cmp r5, #0x00
	bge _08001FB2
	ldr r4, _08002040 @ =0x030074C8
	ldr r0, [r4, #0x00]
	ldr r1, _08002044 @ =0x00001A94
	adds r0, r0, r1
	bl func_08000BA4
	adds r6, r4, #0x0
	ldr r4, _08002048 @ =0x00001814
	movs r5, #0x0F
_08001FDE:
	ldr r1, [r6, #0x00]
	adds r2, r1, r4
	adds r0, r2, #0x0
	adds r0, #0x0C
	ldr r3, _08002044 @ =0x00001A94
	adds r1, r1, r3
	bl func_08000BB0
	adds r4, #0x28
	subs r5, #0x01
	cmp r5, #0x00
	bge _08001FDE
	movs r2, #0x00
	ldr r4, _08002040 @ =0x030074C8
	ldr r1, [r4, #0x00]
	ldr r3, _0800204C @ =0x000028A8
	adds r0, r1, r3
	movs r5, #0x00
	strh r2, [r0, #0x00]
	ldr r3, _08002050 @ =0x00002BAC
	adds r0, r1, r3
	strh r2, [r0, #0x00]
	ldr r0, _08002054 @ =0x000028AA
	adds r1, r1, r0
	strh r2, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	bl func_080034EC
	ldr r0, [r4, #0x00]
	ldr r1, _08002058 @ =0x00002BAE
	adds r0, r0, r1
	strb r5, [r0, #0x00]
	ldr r0, [r4, #0x00]
	ldr r3, _0800205C @ =0x00002BAF
	adds r0, r0, r3
	strb r5, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x03
	movs r0, #0x00
	bl func_08001F20
	movs r0, #0x00
	movs r1, #0x10
	bl func_08001F5C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08002040: .4byte 0x030074C8
_08002044: .4byte 0x00001A94
_08002048: .4byte 0x00001814
_0800204C: .4byte 0x000028A8
_08002050: .4byte 0x00002BAC
_08002054: .4byte 0x000028AA
_08002058: .4byte 0x00002BAE
_0800205C: .4byte 0x00002BAF
.syntax divided
