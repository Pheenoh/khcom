.syntax unified
	.align 2, 0
	.global task_smn_cloud_3
	.thumb
	.thumb_func
	.type task_smn_cloud_3, %function
task_smn_cloud_3: @ 08041D1C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _08041D30 @ =0x00000163
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08041D38
	ldr r0, _08041D34 @ =0x02039B84
	b _08041D3A
	.byte 0x00, 0x00
_08041D30: .4byte 0x00000163
_08041D34: .4byte 0x02039B84
_08041D38:
	ldr r0, _08041D5C @ =0x02039B9C
_08041D3A:
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _08041D60 @ =0xFFDFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	ldr r0, [r4, #0x04]
	bl func_08002C10
	adds r0, r4, #0x0
	adds r0, #0x20
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
_08041D5C: .4byte 0x02039B9C
_08041D60: .4byte 0xFFDFFFFF
.syntax divided
