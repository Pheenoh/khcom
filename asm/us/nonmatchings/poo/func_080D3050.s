.syntax unified
	.align 2, 0
	.global func_080D3050
	.thumb
	.thumb_func
	.type func_080D3050, %function
func_080D3050: @ 080D3050
	push {r4, lr}
	add sp, #-0x024
	mov r1, sp
	ldr r0, _080D30B4 @ =0x096FDB40
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r3, _080D30B8 @ =0x02034E38
	ldrh r1, [r3, #0x00]
	adds r1, #0x01
	strh r1, [r3, #0x00]
	ldr r2, _080D30BC @ =0x02034E3A
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x02
	add r0, sp
	ldrh r0, [r0, #0x02]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r0
	bcc _080D30AC
	movs r1, #0x00
	strh r1, [r3, #0x00]
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x02
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, #0xFF
	bne _080D3096
	strh r1, [r2, #0x00]
_080D3096:
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x02
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x05
	ldr r1, _080D30C0 @ =0x0984A138
	adds r0, r0, r1
	ldr r1, _080D30C4 @ =0x05000040
	movs r2, #0x20
	bl func_08005BE8
_080D30AC:
	add sp, #0x024
	pop {r4}
	pop {r0}
	bx r0
_080D30B4: .4byte 0x096FDB40
_080D30B8: .4byte 0x02034E38
_080D30BC: .4byte 0x02034E3A
_080D30C0: .4byte 0x0984A138
_080D30C4: .4byte 0x05000040
.syntax divided
