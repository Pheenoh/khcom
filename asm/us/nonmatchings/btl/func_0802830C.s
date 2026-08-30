.syntax unified
	.align 2, 0
	.global func_0802830C
	.thumb
	.thumb_func
	.type func_0802830C, %function
func_0802830C: @ 0802830C
	push {r4, r5, r6, r7, lr}
	movs r4, #0x80
	lsls r4, r4, #0x09
	movs r7, #0x00
	ldr r0, _08028364 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x80
	bl func_08000C8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0802835A
	ldr r5, _08028368 @ =0x01000000
	ldr r6, _0802836C @ =0x00000000
_08028328:
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	ands r0, r5
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0802834C
	adds r0, r2, #0x0
	adds r0, #0xA2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x08
	ldr r1, [r2, #0x0C]
	subs r1, r1, r0
	cmp r4, r1
	ble _0802834C
	adds r7, r2, #0x0
	adds r4, r1, #0x0
_0802834C:
	adds r0, r2, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	bne _08028328
_0802835A:
	adds r0, r7, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08028364: .4byte 0x02039B84
_08028368: .4byte 0x01000000
_0802836C: .4byte 0x00000000
.syntax divided
