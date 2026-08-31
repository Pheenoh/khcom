.syntax unified
	.align 2, 0
	.global mode_ms_charge_2
	.thumb
	.thumb_func
	.type mode_ms_charge_2, %function
mode_ms_charge_2: @ 08106F90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _081070C4 @ =0x02035D90
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _081070C8 @ =0x02035D9C
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _081070CC @ =0x02035DB8
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _081070D0 @ =0x02035C40
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _081070D4 @ =0x02035C44
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _081070D8 @ =0x02035C48
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _081070DC @ =0x02035C80
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _081070E0 @ =0x02035C84
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _081070E4 @ =0x02035CC0
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _081070E8 @ =0x02035CC4
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	movs r1, #0x00
	ldr r0, _081070EC @ =0x02035CE8
	mov r8, r0
_08106FEC:
	lsls r0, r1, #0x01
	adds r7, r1, #0x1
	adds r0, r0, r1
	lsls r0, r0, #0x02
	mov r1, r8
	adds r5, r0, r1
	adds r4, r0, #0x0
	movs r6, #0x02
_08106FFC:
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _08107006
	bl ReleaseObjPalette
_08107006:
	ldr r0, _081070F0 @ =0x02035D18
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08107014
	bl ReleaseObjTiles
_08107014:
	adds r5, #0x04
	adds r4, #0x04
	subs r6, #0x01
	cmp r6, #0x00
	bge _08106FFC
	adds r1, r7, #0x0
	cmp r1, #0x03
	ble _08106FEC
	ldr r0, _081070F4 @ =0x02035D84
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08107030
	bl ReleaseObjPalette
_08107030:
	ldr r0, _081070F8 @ =0x02035D88
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0810703C
	bl ReleaseObjTiles
_0810703C:
	ldr r0, _081070FC @ =0x02035D94
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08107048
	bl ReleaseObjTiles
_08107048:
	ldr r4, _08107100 @ =0x02035DDC
	ldr r0, [r4, #0x00]
	movs r1, #0x24
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl EwramFree
	ldr r4, _08107104 @ =0x02035DE4
	ldr r0, [r4, #0x00]
	movs r1, #0x5A
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl EwramFree
	ldr r4, _08107108 @ =0x02035DEC
	ldr r0, [r4, #0x00]
	ldr r1, _0810710C @ =0x02035DF2
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl EwramFree
	ldr r4, _08107110 @ =0x02035DF4
	ldr r0, [r4, #0x00]
	ldr r1, _08107114 @ =0x02035DFA
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl EwramFree
	ldr r4, _08107118 @ =0x02035DFC
	ldr r0, [r4, #0x00]
	ldr r1, _0810711C @ =0x02035E02
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl EwramFree
	ldr r4, _08107120 @ =0x02035E04
	ldr r0, [r4, #0x00]
	ldr r1, _08107124 @ =0x02035E0A
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl EwramFree
	ldr r0, _08107128 @ =0x02035C10
	ldr r0, [r0, #0x00]
	bl EwramFree
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081070C4: .4byte 0x02035D90
_081070C8: .4byte 0x02035D9C
_081070CC: .4byte 0x02035DB8
_081070D0: .4byte 0x02035C40
_081070D4: .4byte 0x02035C44
_081070D8: .4byte 0x02035C48
_081070DC: .4byte 0x02035C80
_081070E0: .4byte 0x02035C84
_081070E4: .4byte 0x02035CC0
_081070E8: .4byte 0x02035CC4
_081070EC: .4byte 0x02035CE8
_081070F0: .4byte 0x02035D18
_081070F4: .4byte 0x02035D84
_081070F8: .4byte 0x02035D88
_081070FC: .4byte 0x02035D94
_08107100: .4byte 0x02035DDC
_08107104: .4byte 0x02035DE4
_08107108: .4byte 0x02035DEC
_0810710C: .4byte 0x02035DF2
_08107110: .4byte 0x02035DF4
_08107114: .4byte 0x02035DFA
_08107118: .4byte 0x02035DFC
_0810711C: .4byte 0x02035E02
_08107120: .4byte 0x02035E04
_08107124: .4byte 0x02035E0A
_08107128: .4byte 0x02035C10
.syntax divided
