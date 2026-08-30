.syntax unified
	.align 2, 0
	.global task_smn_genie_3
	.thumb
	.thumb_func
	.type task_smn_genie_3, %function
task_smn_genie_3: @ 08044DF0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	ldr r0, _08044E24 @ =0x02039B84
	ldr r6, [r0, #0x00]
	ldr r2, [r6, #0x68]
	ldr r3, [r6, #0x6C]
	ldr r0, _08044E28 @ =0x00040000
	ldr r1, _08044E2C @ =0x00000000
	adds r4, r2, #0x0
	orrs r4, r0
	adds r5, r3, #0x0
	str r4, [r6, #0x68]
	str r5, [r6, #0x6C]
	ldr r1, _08044E30 @ =0x00000151
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08044E38
	ldr r2, _08044E34 @ =0xFFDFFFFF
	adds r0, r4, #0x0
	ands r0, r2
	adds r1, r5, #0x0
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	b _08044E48
	.byte 0x00, 0x00
_08044E24: .4byte 0x02039B84
_08044E28: .4byte 0x00040000
_08044E2C: .4byte 0x00000000
_08044E30: .4byte 0x00000151
_08044E34: .4byte 0xFFDFFFFF
_08044E38:
	ldr r0, _08044E5C @ =0x02039B9C
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _08044E60 @ =0xFFDFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
_08044E48:
	ldr r0, [r7, #0x04]
	bl func_08002C10
	adds r0, r7, #0x0
	adds r0, #0x20
	bl func_08000F0C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08044E5C: .4byte 0x02039B9C
_08044E60: .4byte 0xFFDFFFFF
.syntax divided
