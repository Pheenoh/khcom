.syntax unified
	.align 2, 0
	.global func_0810D304
	.thumb
	.thumb_func
	.type func_0810D304, %function
func_0810D304: @ 0810D304
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	movs r7, #0x00
	cmp r1, #0x00
	bge _0810D338
	movs r4, #0x00
	adds r6, r5, #0x0
	adds r6, #0xC4
	b _0810D318
_0810D316:
	adds r4, #0x01
_0810D318:
	ldr r0, [r6, #0x00]
	cmp r4, r0
	bge _0810D35C
	lsls r1, r4, #0x02
	movs r2, #0x81
	lsls r2, r2, #0x04
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08110938
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bne _0810D316
	b _0810D35A
_0810D338:
	adds r0, r5, #0x0
	adds r0, #0xC4
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bge _0810D35C
	lsls r1, r1, #0x02
	movs r2, #0x81
	lsls r2, r2, #0x04
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08110938
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bne _0810D35C
_0810D35A:
	movs r7, #0x01
_0810D35C:
	adds r0, r7, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
