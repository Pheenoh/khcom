.syntax unified
	.align 2, 0
	.global func_0810D478
	.thumb
	.thumb_func
	.type func_0810D478, %function
func_0810D478: @ 0810D478
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r5, #0x00
	b _0810D4A2
_0810D480:
	lsls r1, r5, #0x02
	movs r2, #0x81
	lsls r2, r2, #0x04
	adds r0, r6, r2
	adds r4, r0, r1
	ldr r0, [r4, #0x00]
	bl func_08110918
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bne _0810D49E
	ldr r0, [r4, #0x00]
	bl func_081109A8
_0810D49E:
	adds r5, #0x01
	adds r0, r6, #0x0
_0810D4A2:
	adds r0, #0xC4
	ldr r0, [r0, #0x00]
	cmp r5, r0
	blt _0810D480
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
