.syntax unified
	.align 2, 0
	.global task_smn_tink_3
	.thumb
	.thumb_func
	.type task_smn_tink_3, %function
task_smn_tink_3: @ 08042F30
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _08042F44 @ =0x00000153
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08042F4C
	ldr r0, _08042F48 @ =0x02039B84
	b _08042F4E
	.byte 0x00, 0x00
_08042F44: .4byte 0x00000153
_08042F48: .4byte 0x02039B84
_08042F4C:
	ldr r0, _08042F78 @ =0x02039B9C
_08042F4E:
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _08042F7C @ =0xFFDFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	ldr r0, _08042F80 @ =0x0000024F
	bl func_0811FF3C
	ldr r0, [r4, #0x04]
	bl func_08002C10
	adds r0, r4, #0x0
	adds r0, #0x20
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08042F78: .4byte 0x02039B9C
_08042F7C: .4byte 0xFFDFFFFF
_08042F80: .4byte 0x0000024F
.syntax divided
