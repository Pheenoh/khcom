.syntax unified
	.align 2, 0
	.global task_hum_mahluxia_2
	.thumb
	.thumb_func
	.type task_hum_mahluxia_2, %function
task_hum_mahluxia_2: @ 08050D14
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	bl func_0800EFE8
	movs r1, #0xE8
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrh r1, [r0, #0x00]
	movs r2, #0x02
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08050DCA
	movs r3, #0xDE
	lsls r3, r3, #0x01
	adds r0, r4, r3
	ldrh r1, [r0, #0x00]
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08050DCA
	movs r5, #0xEC
	lsls r5, r5, #0x01
	adds r0, r4, r5
	movs r6, #0x00
	ldsh r0, [r0, r6]
	movs r1, #0x0C
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x0B
	bhi _08050DBE
	lsls r0, r0, #0x02
	ldr r1, _08050D60 @ =0x08050D64
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
_08050D60: .4byte 0x08050D64
	.byte 0x94, 0x0D, 0x05, 0x08, 0x9C, 0x0D, 0x05, 0x08, 0x94, 0x0D, 0x05, 0x08, 0x9C, 0x0D, 0x05, 0x08
	.byte 0x94, 0x0D, 0x05, 0x08, 0xA4, 0x0D, 0x05, 0x08, 0x94, 0x0D, 0x05, 0x08, 0x9C, 0x0D, 0x05, 0x08
	.byte 0x94, 0x0D, 0x05, 0x08, 0xA4, 0x0D, 0x05, 0x08, 0x94, 0x0D, 0x05, 0x08, 0xB2, 0x0D, 0x05, 0x08
	.byte 0x8F, 0x20, 0x80, 0x00, 0x21, 0x18, 0x06, 0xE0, 0xA7, 0x23, 0x9B, 0x00, 0xE1, 0x18, 0x02, 0xE0
	.byte 0xBF, 0x25, 0xAD, 0x00, 0x61, 0x19, 0x20, 0x1C, 0xFE, 0xF7, 0x92, 0xFE, 0x05, 0xE0, 0xD7, 0x26
	.byte 0xB6, 0x00, 0xA1, 0x19, 0x20, 0x1C, 0xFE, 0xF7, 0x8B, 0xFE
_08050DBE:
	movs r0, #0xEC
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_08050DCA:
	movs r1, #0xCB
	lsls r1, r1, #0x02
	adds r2, r4, r1
	movs r3, #0xD7
	lsls r3, r3, #0x02
	adds r1, r4, r3
	adds r0, r2, #0x0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	movs r5, #0xBF
	lsls r5, r5, #0x02
	adds r1, r4, r5
	adds r0, r1, #0x0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	movs r6, #0xB3
	lsls r6, r6, #0x02
	adds r2, r4, r6
	adds r0, r2, #0x0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	movs r0, #0xA7
	lsls r0, r0, #0x02
	adds r1, r4, r0
	adds r0, r1, #0x0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	movs r0, #0x9B
	lsls r0, r0, #0x02
	adds r2, r4, r0
	adds r0, r2, #0x0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	movs r0, #0x8F
	lsls r0, r0, #0x02
	adds r1, r4, r0
	adds r0, r1, #0x0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	movs r0, #0x83
	lsls r0, r0, #0x02
	adds r2, r4, r0
	adds r0, r2, #0x0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	movs r0, #0xEE
	lsls r0, r0, #0x01
	adds r1, r4, r0
	adds r0, r1, #0x0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	adds r0, r4, #0x0
	bl func_0804FA70
	movs r1, #0xE4
	lsls r1, r1, #0x02
	adds r0, r4, r1
	bl func_08000EE0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
